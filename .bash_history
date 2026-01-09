groups
docker
docker ps
docker run hello-world
ls -l /var/run/docker.sock
sudo apt update
sudo apt install docker.io docker-compose -y
sudo systemctl start docker
sudo systemctl enable docker
sudo apt remove containerd -y
sudo apt update
sudo apt install docker.io docker-compose -y
docker --version
docker-compose --version
sudo apt-get autoremove --purge containerd.io containerd docker-ce docker-ce-cli
sudo apt update
sudo apt install docker.io docker-compose -y
docker --version && docker-compose --version
sudo apt update
sudo apt install docker-compose-plugin -y
docker compose version
mkdir sis-project
cd sis-project
touch Dockerfile docker-compose.yml Dockerfile.db .dockerignore
ls
Dockerfile  Dockerfile.db  docker-compose.yml  .dockerignore
nano .dockerignore
nano Dockerfile
nano Dockerfile.db
nano docker-compose.yml
docker compose up --build
docker ps
git add Dockerfile Dockerfile.db docker-compose.yml .dockerignore
git commit -m "feat: complete Docker infrastructure (Week 2)"
git push origin develop
cd ~/sis-project
git status
git add Dockerfile Dockerfile.db docker-compose.yml .dockerignore
git commit -m "Week 2: Docker infrastructure setup"
git push origin develop
git config --global user.name "omar-badubais"
git config --global user.email "omar.badubais@stu.fbu.edu.tr"
git config --global --list
user.name=omar-badubais
user.email=omar.badubais@stu.fbu.edu.tr
git commit -m "Week 2: Docker infrastructure setup"
git checkout -b develop
git push -u origin develop
git config --global user.name "omar-badubais"
git config --global user.email "omar.badubais@stu.fbu.edu.tr"
git config --global --list
git remote -v
git remote set-url origin git@github.com:omar-badubais/me.git
git remote -v
ls ~/.ssh
ssh-keygen -t ed25519 -C "omar.badubais@stu.fbu.edu.tr"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
cat ~/.ssh/id_ed25519.pub
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
cat ~/.ssh/id_ed25519.pub
ssh -T git@github.com
nano Dockerfile
