Before executing the commands, the following should be installed on the Ubuntu system:
Git: For cloning a repository on GitHub.
Docker: Used for running applications in a Docker environment.
Docker Compose: To compose the services of the database and app.
-
Downloading the Project (Cloning)
Open your terminal in Ubuntu and run the following commands to download the latest code from the develop branch :
git clone https://github.com/Jasim427/System-Programming.git
cd sis-project
-
The system is designed to start both the PostgreSQL Database and the C++ Application with a single command
docker-compose up --build

What happens during this process? Image Pulling: Docker pulls the official postgres:latest image for the database container.
Building: Docker builds a custom image for the C++ application using the project's Dockerfile.
Networking: A private internal network is created to allow the App and DB to communicate.
Volumes: A persistent volume is created to ensure student data is not lost if the container stops
-
After the command finishes, verify the status of the containers:
Check Status: Run docker ps. You should see two containers: sis-db and sis-app.
Interaction: The C++ CLI (Command Line Interface) will appear, allowing you to Save, List, Update, or Delete student information.
-
To stop the services and clean up the containers, use the following command:
docker-compose down
