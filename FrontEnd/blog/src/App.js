import React, {useRef, useState} from 'react';
import './App.css';

function App() {
  let [blogs,setBlogs] = useState([{title: "제목", content: "내용", day: "2024-02-04", like: 0}, {title: "제목2", content: "내용2", day: "2024-02-04", like: 0}]);
  let [current,setCurrent] = useState(-1)
  let titleRef = useRef()
  let contentRef = useRef()

  function addBlog() {
    if (titleRef.current && contentRef.current) {
      if (titleRef.current.value !== "" && contentRef.current.value !== "") {
        const now = new Date()
        const day = now.toISOString()
        const blog = {
          title: titleRef.current.value,
          content: contentRef.current.value,
          day: ` ${day.substring(0,10)}`,
          like: 0}
        setBlogs(prev => [...prev,blog])
        titleRef.current.value = ""
        contentRef.current.value = ""
      } else {
        console.log("빈칸 채워넣어")
      }
    }
  }

  return (
    <div className="App">
      <div className="black-nav">
        <div>개발 Blog</div>
        <div onClick={() => {setCurrent(-1)}}>블로그 추가</div>
      </div>

      {blogs.map((blog, index) => (
        <div className="list" onClick={() => {setCurrent(index)}}>
          <h3>{blog.title} <span onClick={()=>{blog.like += 1}}>👍</span>{blog.like}</h3>
          <p>{blog.day}</p>
          <hr />
        </div>
      ))}

      {current !== -1 &&
        <div className="modal">
          <h2>{blogs[current].title}</h2>
          <p>{blogs[current].content}</p>
          <p>{blogs[current].day} {blogs[current].like}</p>
        </div>
      }
      {current === -1 &&
        <div className='addition'>
          <div>제목</div>
          <input ref={titleRef} type="text" />
          <div>내용</div>
          <textarea ref={contentRef} />
          <div onClick={addBlog}>제출</div>
        </div>
      }

    </div>
  );
}

export default App;
