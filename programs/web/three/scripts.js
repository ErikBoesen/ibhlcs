// Set the scene size.
const WIDTH = window.innerWidth;
const HEIGHT = window.innerHeight;

// Set some camera attributes.
const VIEW_ANGLE = 45;
const ASPECT = WIDTH / HEIGHT;
const NEAR = 0.1;
const FAR = 10000;

// Get the DOM element to attach to
const container = document.querySelector('#three');

// Create a WebGL renderer, camera
// and a scene
const renderer = new THREE.WebGLRenderer({
    //alpha: true,
    antialias: true,
});
const camera =
    new THREE.PerspectiveCamera(
        VIEW_ANGLE,
        ASPECT,
        NEAR,
        FAR
    );

const scene = new THREE.Scene();

// Add the camera to the scene.
scene.add(camera);

// Start the renderer.
renderer.setSize(WIDTH, HEIGHT);

// Attach the renderer-supplied
// DOM element.
container.appendChild(renderer.domElement);

const RADIUS = 50;
const SEGMENTS = 16;
const RINGS = 16;

var geometry = new THREE.BoxGeometry( 1, 1, 1 );
var material = new THREE.MeshNormalMaterial();
var cube = new THREE.Mesh( geometry, material );
scene.add( cube );


camera.position.z = 2;

// create a point light
const pointLight =
  new THREE.PointLight(0xFFFFFF);

// set its position
pointLight.position.x = 10;
pointLight.position.y = 50;
pointLight.position.z = 130;

// add to the scene
scene.add(pointLight);

var cubeDirection = 1;
function animate() {
  // Schedule the next frame.
  requestAnimationFrame(animate);

  cube.rotation.x += 0.1;
  cube.rotation.y += 0.1;
  if (cube.position.z > 0 || cube.position.z < -20)
    cubeDirection *= -1;
  cube.position.z += cubeDirection * 0.1;
  console.log(cube.position.z);

  // Draw!
  renderer.render(scene, camera);
}

animate();
