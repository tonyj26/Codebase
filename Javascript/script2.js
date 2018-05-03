//examine the document object //

//console.dir(document);

console.log(document.domain);
console.log(document.URL);
console.log(document.title);
//document.title = 123;
console.log(document.doctype);
console.log(document.head);
console.log(document.body);
console.log(document.all);

//console.log(document.getElementById("test"));

var par = document.getElementById('test');

console.log(par);
par.innerText = 'innerHTML';
