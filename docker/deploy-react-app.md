To deploy a React app built using Vite on a Dockerized Linux server, you can follow these steps:

### 1. Build the React App with Vite

First, ensure your React app is ready for production. Run the following command to create a production build using Vite:

```bash
npm run build
```

This will generate a `dist/` folder containing the production build of your app.

### 2. Create a Dockerfile

Next, create a `Dockerfile` in your project root (same level as `package.json`) to set up the Docker image for your app. Here is a simple Dockerfile for serving your React app using a lightweight Nginx web server:

```Dockerfile
# Step 1: Build the app using Node.js
FROM node:18 AS build

# Set the working directory
WORKDIR /app

# Copy the package.json and package-lock.json (or yarn.lock) to install dependencies
COPY package*.json ./

# Install dependencies
RUN npm install

# Copy the rest of the application code
COPY . .

# Build the React app using Vite
RUN npm run build

# Step 2: Serve the app using Nginx
FROM nginx:alpine

# Copy the build output to the Nginx server directory
COPY --from=build /app/dist /usr/share/nginx/html

# Expose port 80
EXPOSE 80

# Start Nginx
CMD ["nginx", "-g", "daemon off;"]
```

### Explanation of the Dockerfile:
1. **Build stage**:  
   - Use the official Node.js image to build the app.
   - Set up the working directory, copy dependencies, and run the build command using `npm run build`.
   
2. **Production stage**:  
   - Use the Nginx image to serve the static files.
   - Copy the contents of the `dist/` directory (the production build) from the build stage into Nginx’s HTML directory (`/usr/share/nginx/html`).
   - Expose port 80 (the default port for HTTP traffic).
   - Use the `CMD` command to run Nginx in the foreground.

### 3. Build the Docker Image

Next, build the Docker image for your app by running the following command in the root of your project (where the Dockerfile is located):

```bash
docker build -t my-react-app .
```

This will create a Docker image named `my-react-app`.

### 4. Run the Docker Container

After building the image, run the container using the following command:

```bash
docker run -p 80:80 my-react-app
```

This will map port 80 on your Docker container to port 80 on your Linux server, allowing you to access your React app in a browser via the server's IP address or domain.

### 5. (Optional) Push to a Docker Registry

If you're deploying to a remote server, you may want to push your Docker image to a Docker registry (such as Docker Hub) for easy deployment.

To push the image to Docker Hub:

1. Log in to Docker Hub:

   ```bash
   docker login
   ```

2. Tag your image with your Docker Hub username and repository:

   ```bash
   docker tag my-react-app <your-username>/my-react-app:latest
   ```

3. Push the image to Docker Hub:

   ```bash
   docker push <your-username>/my-react-app:latest
   ```

### 6. Deploy to a Linux Server

If you're deploying to a remote Linux server, you can either:
- **SSH into the server**, install Docker, and then pull the Docker image from Docker Hub (or your private registry), or
- **Push the image to your registry** and then pull the image onto your server.

To pull and run the app on your Linux server:

```bash
docker pull <your-username>/my-react-app:latest
docker run -p 80:80 <your-username>/my-react-app:latest
```

This should successfully deploy your React app built with Vite in Docker on a Linux server!

### 7. Project Structure
```sh
/my-react-app
  ├── Dockerfile
  ├── package.json
  ├── package-lock.json
  ├── src/
  ├── public/
  └── .env
```

### 8. Adding ```.dockerignore ``` to project root directory
```sh
node_modules
.git
.DS_Store
```
