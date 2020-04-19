//객체 깊은 복사
function clone(obj) {
  let ret = {};
  for(let key in obj) {
    ret[key] = obj[key];
  }
  return ret;
}

//주어진 디렉토리 / mkdir 명령어에서 사용할 트리구조화
function make_tree(tree, arr) {
  if(!arr.length) return tree; //arr 비었으면 tree 리턴
  let front = arr.shift();
  if(front) {
    if(!tree[front]) tree[front] = {}; //해당 디렉토리가 없는 경우만 생성
  }
  else return tree; //arr의 값이 falsy라면 tree 리턴
  return make_tree(tree[front], arr);
}

function rm_tree(tree, arr) {
  let front = arr.shift();
  if(arr.length) return rm_tree(tree[front], arr);
  delete tree[front];
}

//cp 명령어에서 source 트리 반환
function source_tree(tree, arr) {
  if(!arr.length) return tree;
  let front = arr.shift();
  if(!front) return tree;
  if(arr.length) return source_tree(tree[front], arr);
  return [front,tree[front]];
}

//디렉토리 트리 배열로 변환
function reduce_tree(tree, accum, arr) {
  for(let key in tree) {
    let str = accum;
    if(accum && accum != '/') str += "/";
    str += key;
    arr.push(str);
    reduce_tree(tree[key], str, arr);
  }
  return arr;
}

function solution(directory, command) {
  const tree = {"/":{}};
  directory.forEach(d=> {
    make_tree(tree["/"],d.slice(1).split("/"));
  });
  command.forEach(c=> {
    const [cmd, src, dest] = c.split(" ");
    if(cmd === "mkdir") make_tree(tree["/"],src.slice(1).split("/"));
    if(cmd === "rm") rm_tree(tree["/"],src.slice(1).split("/"));
    if(cmd === "cp") {
      const [name, source] = source_tree(tree["/"], src.slice(1).split("/"));
      const destination = dest_tree(tree["/"], dest.slice(1).split("/"));
      //destination 트리 반환
      function dest_tree(sub, arr) {
        if(!arr.length) return sub;
        let front = arr.shift();
        if(!front) return sub;
        if(arr.length) return dest_tree(sub[front], arr);
        return sub[front];
      }
      destination[name] = clone(source);
      //clone 함수를 정의하는 것 대신 JSON.parse(JSON.stringify(source)) 를 이용해 깊은 복사 가능.
      //그러나 JSON 메서드는 성능면에서 다른 방법에 비해 느림.
      //clone 없이 desination[name] = source 하게 되면 얕은 복사를 하기 때문에 rm 하는 경우에 문제가 발생.
      //따라서 얕은 복사가 아닌 깊은 복사를 통해 새로운 객체를 생성해야 함.
    }
  })
  return reduce_tree(tree, "", []);
}

const directory1 = [
  "/",
  "/hello",
  "/hello/tmp",
  "/root",
  "/root/abcd",
  "/root/abcd/etc",
  "/root/abcd/hello"
];
const command1 = [
  "mkdir /root/tmp",
  "cp /hello /root/tmp", 
  "rm /hello"
];

const directory2 = [
  "/"
]
const command2 = [
  "mkdir /a",
  "mkdir /a/b",
  "mkdir /a/b/c",
  "cp /a/b /",
  "rm /a/b/c"
]

console.log(solution(directory1, command1));
console.log(solution(directory2, command2))