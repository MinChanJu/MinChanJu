const express = require('express')
var cors = require('cors')
require('dotenv').config();
const { createClient } = require('@supabase/supabase-js');

const supabaseUrl = process.env.SUPABASE_URL;
const supabaseKey = process.env.SUPABASE_KEY;
const supabase = createClient(supabaseUrl, supabaseKey);

const app = express()
const port = 3000

app.use(cors())

app.get('/', function (req, res) {
    res.send('Hello World')
})

app.get('/allContest', async function(req, res) {
    const { data, error } = await supabase
      .from('contests')
      .select('contest_name, id, created_at, contest_description, user_id')
      .order('created_at', { ascending: false })
  
    if (error) {
      return res.send(error.message)
    }
  
    return res.send(data)
})

app.get('/user/:id', function (req, res) {
    const p = req.params
    console.log(p.id)
    const q = req.query
    console.log(q)
    res.send({'userId': q.age})
})

app.get('/sound/:name', function (req, res) {
    const { name } = req.params
    if (name == "dog") { res.json({'sound': '멍멍'}) }
    else if (name == "cat") { res.json({'sound': '야옹'}) }
    else if (name == "pig") { res.json({'sound': '꿀꿀'}) }
    else { res.json({'sound': '알 수 없음'}) }
})

app.listen(port, () => { console.log(`open in\nhttp://localhost:${port}`) })