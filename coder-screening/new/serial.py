class CustomUserSerializer(serializers.HyperlinkedModelSerializer):
    email = serializers.EmailField(required=True)
​
    class Meta:
        model = CustomUser
        fields = ['fullname', 'email','password', 'is_active', 'date_joined']
​
model.py 
class CustomUser(models.Model):
    fullname= models.CharField(max_length=50, blank=True)
    email= models.CharField(max_length=57)
    password= models.CharField(max_length=20, null=True )
    is_active= models.BooleanField(default=False)
    date_joined=models.DateTimeField(default=timezone.now)
view.py
@api_view(['POST', 'GET'])
def register(request):
     if request.method == "POST":
          print (request.POST)
          serializer = CustomUserSerializer(data=request.data)
          if  serializer.is_valid():
           user = serializer.save()
        #    user.password(request.data.get('password'))
        #    user = user.save()
           user = authenticate(request, email=request.data.get('email'), password=request.data.get('password'))
           if user is not None:
            register(request, user)
           token, _ = Token.objects.get_or_create(user=user)
           # Expires in one day
           refresh = RefreshToken.for_user(user, lifetime=timedelta(days=1))
           return Response({
               "token": str(refresh.access_token), 
               "user": CustomUserSerializer(user).data}, status=status.HTTP_201_CREATED)
          else:
            return Response({"error": "Invalid credentials"}, status=status.HTTP_400_BAD_REQUEST)
     elif request.method == "GET":
       return render(request, 'register.html')