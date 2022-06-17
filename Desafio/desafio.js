fetch("http://jsonplaceholder.typicode.com/users")
.then(r => r.json())
.then(jsonBody=> {
        jsonBody.forEach(objeto => {
            document.querySelector("#lista").innerHTML += `<li> ${ objeto.name} </li>`        
        })
    }
).catch(error => console.log('Algum problema no servidor: ' + error.message));

//usando for
// for(var i = 0; i < jsonBody.length; i++) {
//         document.querySelector("#lista").innerHTML += `<li> ${ jsonBody[i].name } </li>`
//     }
// }

//usando forEach
// .then(jsonBody=> {
//     jsonBody.forEach(objeto => {
//         document.querySelector("#lista").innerHTML += `<li> ${ objeto .name} </li>`        
//     })
// }