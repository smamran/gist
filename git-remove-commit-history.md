### [Git Or GitHub Remove Commit History](https://stackoverflow.com/questions/9683279/make-the-current-commit-the-only-initial-commit-in-a-git-repository)

### First Way

* Here's the brute-force approach. It also removes the configuration of the repository.

* Note: This does NOT work if the repository has submodules! If you are using submodules, you should use e.g. interactive rebase

#### Step 1: remove all history (Make sure you have backup, this cannot be reverted)
```sh
rm -rf .git
```

#### Step 2: reconstruct the Git repo with only the current content
```sh
git init
git add .
git commit -m "Initial commit"
```
#### Step 3: push to GitHub.

```sh
git remote add origin <github-uri> [Clone with HTTPS URL]
git push -u --force origin master
```

## Second Way
#### Delete the .git folder may cause problems in your git repository. If you want to delete all your commit history.

#### Follow steps:

#### step-1 (checkout)
```sh
git checkout --orphan latest_branch
```

#### step-2 (Add all the files)
```sh
git add -A
```

#### step-3 (Commit the changes)
```sh
git commit -am "commit message"
```

#### step-4 (Delete the branch)
```sh
git branch -D master
```
#### step-5 (Rename the current branch to master)
```sh
git branch -m master
```

#### Step-6 (Final step, force to update your repository)
```sh
git push -f origin master
```
#### !! Now Enjoy your commit history deleted !!
