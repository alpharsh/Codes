# Git Command Notes

### Working Directory -> Staging Area -> Commit (Local Repository) -> Remote Repository

![Image](https://iili.io/JP3IeDB.png)

### Basic Commands
- `ls` or `ls -a` : List directory contents
- `dir` : List directory contents in Windows
- `cls` : Clears the screen

### Navigation Commands
- `cd "File Name"` : Move forward (in a directory/folder). For paths with spaces: `cd '.\DS in C\'`
- `cd ..` : Move backwards
- `mkdir` : Make a new folder

## Git Commands
- `git clone <url>` : Clone a repository from a URL
- `Remove-Item -Recurse -Force .\.git\` : To remove the Git link from a directory

#### Initializing and Setting Up a Repository
- `git init` : Initiate GIT process
- `git remote add origin <link>` : Add remote repository
- `git remote -v` : Verify remote repository
- `git branch` : Check current branch
- `git branch -M main` : Rename current branch to main

#### Working with Files and Staging
- `git status` : Show the status of the working directory and staging area
- `git rm --cached <file>` : Unstage a file (remove file from Git's tracking)
- `git add .` : Add all files to the staging area
- `git commit -m "Message Here"` : Commit changes with a message. Use `-a` to commit directly without staging
- `git push origin main` : Push changes to the 'main' branch

#### Branching and Committing
- `git checkout -b <new-branch-name>` : Create and switch to a new branch
- `git branch` : Show all branches and indicate the current branch
- `git log` : Show commit history
- `git branch -d <branchname>` : Delete a local branch if it has been fully merged with its upstream
- `git branch -D <branchname>` : If the <branchname> branch has not been fully merged but you still want to delete it

#### Git Commands to Go Back to an Old Commit and Update Main Branch
- `git checkout -b temp-branch <SHA>` : Checkout the specific commit
- `git checkout main` : Switch to the main branch
- `git reset --hard <SHA>` : Reset the main branch to the specified commit
- `git push origin main --force` : Force push changes to the remote main branch (if necessary)