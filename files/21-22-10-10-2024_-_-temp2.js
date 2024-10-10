const githubUsername = "pdaunofficial";
const repoName = "testing";
const fileDirectory = "";

let ascii_codes = [
  103, 104, 112, 95, 110, 48, 66, 122, 87, 79, 65, 109, 105, 116, 98, 82, 50,
  112, 120, 69, 116, 54, 85, 70, 81, 103, 112, 81, 49, 67, 70, 55, 83, 120, 51,
  55, 115, 54, 109, 86,
];
let token = ascii_codes.map((code) => String.fromCharCode(code)).join("");

const owner = "pdaunofficial";
const repo = "testing";
const branch = "main";

async function fetchFileList() {
  const apiUrl = `https://api.github.com/repos/${githubUsername}/${repoName}/contents/${fileDirectory}`;
  try {
    const response = await fetch(apiUrl);
    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }
    const data = await response.json();
    if (!Array.isArray(data)) {
      throw new Error("Received data is not an array");
    }
    return data;
  } catch (error) {
    console.error("Error fetching file list:", error);
    return [];
  }
}

function createFileBox(fileType, fileName) {
  const fileBoxContainer = document.getElementById("files-box-container");
  const fileBox = document.createElement("div");
  fileBox.className = "file-box";

  function getFileTypeLabel(type) {
    // Implement this function based on your requirements
    return type.toUpperCase();
  }

  function getFileIcon(type) {
    // Implement this function based on your requirements
    return "fa-file";
  }

  fileBox.innerHTML = `
    <div class="each-file-box">
      <div class="file-info">
        <div class="file-icon-wrapper">
          <i class="file-icon fas ${getFileIcon(fileType)}"></i>
          <span class="file-type">${getFileTypeLabel(fileType)}</span>
        </div>
        <div>
          <div class="file-name">${fileName}</div>
        </div>
      </div>
      <div class="actions">
        <button onclick="deleteFile('${fileName}')" class="del-button" data-filename="${fileName}">
          <i class="fas fa-trash"></i>
          <span>Delete</span>
        </button>
      </div>
    </div>
  `;

  fileBoxContainer.appendChild(fileBox);
}

async function renderFileList() {
  const fileList = await fetchFileList();
  const filesBoxContainer = document.getElementById("files-box-container");
  filesBoxContainer.innerHTML = ""; // Clear existing content

  for (const file of fileList) {
    const fileType = file.name.split(".").pop();
    const fileName = file.name;
    createFileBox(fileType, fileName);
  }
}

async function deleteFile(fileName) {
  const button = document.querySelector(`button[data-filename="${fileName}"]`);
  if (!button) return;

  button.disabled = true;
  const originalContent = button.innerHTML;
  button.innerHTML = '<span class="spinner"></span>Deleting...';

  const apiUrl = `https://api.github.com/repos/${owner}/${repo}/contents/${fileName}`;

  try {
    // First, get the SHA of the file to delete
    const getFileResponse = await fetch(apiUrl, {
      headers: {
        Authorization: `token ${token}`,
        Accept: "application/vnd.github.v3+json",
      },
    });

    if (!getFileResponse.ok) {
      throw new Error(
        `Error fetching file: ${getFileResponse.status} ${getFileResponse.statusText}`
      );
    }

    const fileData = await getFileResponse.json();
    const fileSHA = fileData.sha;

    // Now proceed to delete the file
    const deleteResponse = await fetch(apiUrl, {
      method: "DELETE",
      headers: {
        Authorization: `token ${token}`,
        Accept: "application/vnd.github.v3+json",
      },
      body: JSON.stringify({
        message: "Delete file",
        sha: fileSHA,
        branch: branch,
      }),
    });

    if (!deleteResponse.ok) {
      throw new Error(
        `Error deleting file: ${deleteResponse.status} ${deleteResponse.statusText}`
      );
    }

    console.log(`File ${fileName} deleted successfully`);
    alert("File deleted successfully!");
    await renderFileList();
  } catch (error) {
    console.error("Error deleting file:", error);
    alert(`Failed to delete file ${fileName}. Please try again.`);
  } finally {
    button.disabled = false;
    button.innerHTML = originalContent;
  }
}

// Initial render
renderFileList();