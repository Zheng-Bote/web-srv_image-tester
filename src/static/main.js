window.onload = start;

function start() {}

function dirLs() {
  let input = document.getElementById("dir_ls_in").value;

  if (input.length == 0) {
    alert("Please enter a directory");
  } else {
    get_DirLs(input);
  }
}
async function get_DirLs(path) {
  fetch("/dirls", {
    method: "POST",
    body: JSON.stringify({ target: path }),
  })
    .then(async (response) => {
      // get json response here
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
      }
    })
    .catch((err) => {
      console.error(err);
    });
}

function dirSize() {
  let input = document.getElementById("dir_size_in").value;

  if (input.length == 0) {
    alert("Please enter a directory");
  } else {
    get_DirSize(input);
  }
}
async function get_DirSize(path) {
  fetch("/dirsize", {
    method: "POST",
    body: JSON.stringify({ target: path }),
  })
    .then(async (response) => {
      // get json response here
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
      }
    })
    .catch((err) => {
      console.error(err);
    });
}

function createDirs() {
  let input = document.getElementById("create_dirs_in").value;

  if (input.length == 0) {
    alert("Please enter a directory");
  } else {
    create_Dirs(input);
  }
}
async function create_Dirs(path) {
  fetch("/crdirs", {
    method: "POST",
    body: JSON.stringify({ target: path }),
  })
    .then(async (response) => {
      // get json response here
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
      }
    })
    .catch((err) => {
      console.error(err);
    });
}

function uploadFile() {
  let input = document.getElementById("upload_file_in").value;

  if (input.length == 0) {
    alert("Please choose a file");
  } else {
    upload_File();
  }
}
async function upload_File() {
  //let input = document.getElementById("upload_file_in").value;
  var input = document.querySelector('input[type="file"]');
  var data = new FormData();
  data.append("InputFile", input.files[0]);

  fetch("/uploadfile", {
    method: "POST",
    enctype: "multipart/form-data",
    body: data,
  })
    .then(async (response) => {
      // get json response here
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
      }
    })
    .catch((err) => {
      console.error(err);
    });
}

function listIni() {
  list_ini();
}
async function list_ini() {
  fetch("/listini", {
    method: "GET",
  })
    .then(async (response) => {
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
      }
    })
    .catch((err) => {
      console.error(err);
    });
}

function progInfo() {
  prog_info();
}
async function prog_info() {
  fetch("/proginfo", {
    method: "GET",
  })
    .then(async (response) => {
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
      }
    })
    .catch((err) => {
      console.error(err);
    });
}

function output(data) {
  let output = document.getElementById("section_content");
  output.innerHTML = "";
  let code = document.createElement("code");
  let pre = document.createElement("pre");

  for (const key in data) {
    pre.innerHTML += `${key}: ${data[key]}\n`;
  }

  code.appendChild(pre);
  output.appendChild(code);
}
