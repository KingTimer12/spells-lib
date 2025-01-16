import { exec } from 'child_process';

const errorMessage = (error) => {
  if (error) console.error(`Error executing script: ${error}`)
  return error ? true : false
}

const execCallbacl = (error, stdout, stderr) => {
    if (errorMessage(error)) return;
    console.log(stdout);
}

if (process.platform !== 'win32') exec('sh ./scripts/test', execCallbacl);
else exec('powershell.exe -File ./scripts/test.ps1', execCallbacl);