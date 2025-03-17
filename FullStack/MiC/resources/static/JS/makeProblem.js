document.addEventListener("DOMContentLoaded", function() {
  const makeProblemForm = document.getElementById("makeProblemForm");

  makeProblemForm.addEventListener("submit", function(event) {
    event.preventDefault(); // 폼의 기본 제출 동작을 막습니다.

    const contest = JSON.parse(sessionStorage.getItem('contest'));
    const user = JSON.parse(sessionStorage.getItem('user'));

    const current = user.user_id;
    const contestName = contest.contest_name;
    const problemName = document.getElementById("problemName").value;
    const problemDescription = document.getElementById("problemDescription").value;
    const problemInputDescription = document.getElementById("problemInputDescription").value;
    const problemOutputDescription = document.getElementById("problemOutputDescription").value;
    const problemExampleInput = document.getElementById("problemExampleInput").value;
    const problemExampleOutput = document.getElementById("problemExampleOutput").value;
    const action = event.submitter.value;

    fetch('/.netlify/functions/getMakeProblem', {
      method: 'POST',
      headers: {
          'Content-Type': 'application/json'
      },
      body: JSON.stringify({ 
        current: current,
        contestName: contestName,
        problemName: problemName, 
        problemDescription: problemDescription, 
        problemInputDescription: problemInputDescription, 
        problemOutputDescription: problemOutputDescription,
        problemExampleInput: problemExampleInput, 
        problemExampleOutput: problemExampleOutput })
    })
    .then(response => response.json())
    .then(data => {
      if (data.success) {
        if (action == "add") {
          window.location.href = '/problem/add';
        } else {
          window.location.href = `/contest`;
        }
      } else {
        document.getElementById("message").innerText = data.message;
      }
    })
    .catch((error) => {
      console.error('Error:', error);
      document.getElementById("message").innerText = "An error occurred during login.";
    });
  });
});