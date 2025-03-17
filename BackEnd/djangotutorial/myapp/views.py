from django.shortcuts import render
from django.http import HttpResponse
from myapp.models import Post
from rest_framework.response import Response
from rest_framework.decorators import api_view
from .models import Post
from .serializers import PostSerializer

# Create your views here.
def hello(request):
    return HttpResponse("Hello, Django!")
  
def home(request):
  return render(request, 'home.html')

def all(request):
  Post.objects.all().delete()
  Post.objects.bulk_create([
    Post(title="Post 1", content="내용 1"),
    Post(title="Post 2", content="내용 2"),
    Post(title="Post 3", content="내용 3"),
  ])
  posts = Post.objects.all()  # 모든 게시글 조회
  for post in posts:
    print(post.title, post.content)
  return HttpResponse(posts.first().title + " " + posts.first().content)

# ✅ 모든 게시글 조회 & 새 게시글 추가
@api_view(['GET', 'POST'])
def post_list(request):
    if request.method == 'GET':  # 전체 조회
        posts = Post.objects.all()
        serializer = PostSerializer(posts, many=True)
        return Response(serializer.data)

    elif request.method == 'POST':  # 새 데이터 추가
        serializer = PostSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=201)
        return Response(serializer.errors, status=400)

# ✅ 개별 게시글 조회, 수정, 삭제
@api_view(['GET', 'PUT', 'DELETE'])
def post_detail(request, pk):
    try:
        post = Post.objects.get(pk=pk)
    except Post.DoesNotExist:
        return Response({"error": "Not found"}, status=404)

    if request.method == 'GET':  # 개별 조회
        serializer = PostSerializer(post)
        return Response(serializer.data)

    elif request.method == 'PUT':  # 수정
        serializer = PostSerializer(post, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=400)

    elif request.method == 'DELETE':  # 삭제
        post.delete()
        return Response(status=204)