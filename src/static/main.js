/**
 * @file main.js
 * @author ZHENG Robert (robert.hase-zheng.net)
 * @brief CXX23 webserver to check docker image content
 * @version 0.2.0
 * @date 2025-02-15
 *
 * @copyright Copyright (c) 2025 ZHENG Robert
 */

window.onload = start;

// general functions at document start
function start() {
  document
    .getElementById("header_right")
    .addEventListener("click", function () {
      gotoGithub();
    });
  document.getElementById("footer").addEventListener("click", function () {
    gotoGithubRepo();
  });
}

// general functions
function gotoGithub() {
  window.open("https://github.com/Zheng-Bote");
}
function gotoGithubRepo() {
  window.open("https://github.com/Zheng-Bote/web-srv_image-tester");
}

function showError(err) {
  let section_msg = document.getElementById("section_msg");
  section_msg.style.display = "block";
  section_msg.innerHTML = err;
  setTimeout(hideError, 15000);
}
function hideError() {
  let section_msg = document.getElementById("section_msg");
  section_msg.style.display = "none";
  section_msg.innerHTML = "";
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

async function get_Post(url, path) {
  hideError();

  fetch(`/${url}`, {
    method: "POST",
    body: JSON.stringify({ target: path }),
  })
    .then(async (response) => {
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          showError(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
        showError(data);
      }
    })
    .catch((err) => {
      console.error(err);
      showError(err);
    });
}

async function get_Get(url) {
  hideError();

  fetch(`/${url}`, {
    method: "GET",
  })
    .then(async (response) => {
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          showError(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
        showError(data);
      }
    })
    .catch((err) => {
      console.error(err);
      showError(err);
    });
}

// functions for UI buttons

function dirLs() {
  let input = document.getElementById("dir_ls_in").value;

  if (input.length == 0) {
    alert("Please enter a directory");
  } else {
    get_Post("dirls", input);
  }
}

function dirSize() {
  let input = document.getElementById("dir_size_in").value;

  if (input.length == 0) {
    alert("Please enter a directory");
  } else {
    get_Post("dirsize", input);
  }
}

function createDirs() {
  let input = document.getElementById("create_dirs_in").value;

  if (input.length == 0) {
    alert("Please enter a directory");
  } else {
    get_Post("crdirs", input);
  }
}

function rmDirs() {
  let input = document.getElementById("rm_dirs_in").value;

  if (input.length == 0) {
    alert("Please enter a directory");
  } else {
    get_Post("rmdirs", input);
  }
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
  var input = document.querySelector('input[type="file"]');
  var data = new FormData();
  data.append("InputFile", input.files[0]);

  fetch("/uploadfile", {
    method: "POST",
    enctype: "multipart/form-data",
    body: data,
  })
    .then(async (response) => {
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          showError(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
        showError(data);
      }
    })
    .catch((err) => {
      console.error(err);
      showError(err);
    });
}

function fileSize() {
  let target = document.getElementById("size_file_in").value;

  if (target.length == 0) {
    alert("Please enter a file");
  } else {
    get_Post("filesize", target);
  }
}

function writeTimeFile() {
  let target = document.getElementById("wtime_file_in").value;

  if (target.length == 0) {
    alert("Please enter a file");
  } else {
    get_Post("filewtime", target);
  }
}

function cpFile() {
  let source = document.getElementById("cp_file_source").value;
  let target = document.getElementById("cp_file_target").value;

  if (source.length == 0) {
    alert("Please enter a source directory");
  } else if (target.length == 0) {
    alert("Please enter a target directory");
  } else {
    cp_file(source, target);
  }
}
async function cp_file(source, target) {
  fetch("/cpfile", {
    method: "POST",
    body: JSON.stringify({ target: target, source: source }),
  })
    .then(async (response) => {
      let data = await response.json();

      if (response.status === 200) {
        if (data.error) {
          console.error(data.error);
          showError(data.error);
          output(data);
        } else {
          output(data);
        }
      } else {
        console.error("else status ", data);
        showError(data);
      }
    })
    .catch((err) => {
      console.error(err);
      showError(err);
    });
}

function delFile() {
  let input = document.getElementById("del_file_in").value;

  if (input.length == 0) {
    alert("Please enter a file");
  } else {
    get_Post("rmfile", input);
  }
}

function listIni() {
  get_Get("listini");
}

function progInfo() {
  get_Get("proginfo");
}

function listVMounts() {
  get_Get("getvmounts");
}
