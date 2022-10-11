// 设置画布

const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');

const width = canvas.width = window.innerWidth;
const height = canvas.height = window.innerHeight;

// 生成随机数的函数

function random(min, max) {
  const num = Math.floor(Math.random() * (max - min)) + min;
  return num;
}


function randomColor() {
  return "rgb(" + random(0, 255) + "," + random(0, 255) + "," + random(0, 255) + ")";
}

class Shape {
  constructor(x, y, velX, velY, exists) {
    this.x = x, this.y = y,
      this.velX = velX, this.velY = velY,
      this.exists = exists;
  }
}

class Ball extends Shape {
  constructor(x, y, velX, velY, color, size, exists) {
    super(x, y, velX, velY, exists);
    this.color = color, this.size = size;
  }

  draw() {
    ctx.beginPath();
    ctx.fillStyle = this.color;
    ctx.arc(this.x, this.y, this.size, 0, 2 * Math.PI);
    ctx.fill();
  }

  update() {
    if (this.x + this.size > width || this.x - this.size < 0) {
      this.velX *= -1, this.color = randomColor();
    }
    if (this.y + this.size > height || this.y - this.size < 0) {
      this.velY *= -1, this.color = randomColor();
    }
    this.y += this.velY, this.x += this.velX;
  }

  collisionDetect() {
    for (let ball of balls) {
      if (this != ball) {
        let _x = this.x - ball.x, _y = this.y - ball.y;
        let distance = Math.sqrt(_x * _x + _y * _y);
        if (distance < this.size + ball.size) {
          this.color = ball.color = randomColor();
        }
      }
    }
  }
}

class EvilCircle extends Shape {
  constructor(x, y, exists, color, size) {
    super(x, y, 20, 20, exists);
    this.color = color, this.size = size;
  }

  draw() {
    ctx.beginPath();
    ctx.strokeStyle = this.color;
    ctx.lineWidth = 3;
    ctx.arc(this.x, this.y, this.size, 0, 2 * Math.PI);
    ctx.stroke();
  }

  checkBounds() {
    if (this.x + this.size > width) {
      this.x -= this.size;
    }
    if (this.x - this.size < 0) {
      this.x += this.size;
    }
    if (this.y + this.size > height) {
      this.y -= this.size;
    }
    if (this.y - this.size < 0) {
      this.y += this.size;
    }
  }

  setControl() {
    window.onkeydown = e => {
      switch (e.key) {
        case 'a':
          this.x -= this.velX;
          break;
        case 'd':
          this.x += this.velX;
          break;
        case 'w':
          this.y -= this.velY;
          break;
        case 's':
          this.y += this.velY;
          break;
      }
    };
  }

  collisionDetect() {
    for (let ball of balls) {
      if (ball.exists) {
        let _x = this.x - ball.x, _y = this.y - ball.y;
        let distance = Math.sqrt(_x * _x + _y * _y);
        if (distance < this.size + ball.size) {
          ball.exists = false;
          num--;
        }
      }
    }
  }
}

let balls = [], num = 25;

function addBall() {
  balls.push(new Ball(random(100, 600), random(100, 1400), random(-10, 10), random(-10, 10), randomColor(), random(10, 20), true));
}

for (let i = 0; i < num; i++) {
  addBall();
}

let ec = new EvilCircle(100, 200, true, randomColor(), 10);
ec.setControl();

let textNode = document.getElementById("ballNum");
textNode.innerText = `还剩${num}个小球`;

function loop() {
  ctx.fillStyle = 'rgba(0, 0, 0, 0.25)';
  ctx.fillRect(0, 0, width, height);

  for (let i = 0; i < balls.length; i++) {
    if (balls[i].exists) {
      balls[i].draw();
      balls[i].update();
      balls[i].collisionDetect();
    }
  }
  ec.draw(), ec.checkBounds(), ec.collisionDetect();
  textNode.innerText = `还剩${num}个小球`;
  requestAnimationFrame(loop);
}

loop();