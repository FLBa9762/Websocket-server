let socket = new WebSocket('ws://localhost:7770/');
      socket.addEventListener('open', function (){
          console.log("Cesium连接成功")
          socket.send("cesium_position") 
      })
      socket.addEventListener("close", function(){
          console.log("服务器失去连接")
      })

//操作执行函数
socket.addEventListener('message', function(a){
      try {
        var receive = JSON.parse(a.data);
        console.log("收到发送端的命令: ")
        socket.send("Cesium收到了修改的命令！") 
        FUNCREGISTRY[receive["func_name"]](receive["func_params"]);
      } catch(error){
        console.log("收到其他数据: ")
        console.log(a);
      }
})   

function func_1(json){
  console.log("func_1", json);
}

function func_2(json){
  console.log("func_2", json);
}

function func_3(json){
  console.log("func_3", json);
}

function func_4(json){
  console.log("func_4", json);
}

let FUNCREGISTRY = {
  "func_1": func_1,
  "func_2": func_2,
  "func_3": func_3,
  "func_4": func_4,
}
