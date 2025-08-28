// exp2.js
let cylinderLiquid = document.getElementById("cylinder-liquid");
let bubbles = document.getElementById("bubbles");

let spinachAdded = false;
let h2o2Added = false;

// Function to animate pouring liquid
function pourLiquid(beakerId, color, amount) {
    let liquidHeight = parseInt(cylinderLiquid.style.height);
    liquidHeight += amount;
    cylinderLiquid.style.height = liquidHeight + "px";
    cylinderLiquid.style.backgroundColor = color;
}

// Spinach Paste Beaker Click
document.getElementById("beaker-spinach").addEventListener("click", function() {
    if (!spinachAdded) {
        pourLiquid("beaker-spinach", "green", 40); // 10ml visual
        spinachAdded = true;
    }
    checkReaction();
});

// Hydrogen Peroxide Beaker Click
document.getElementById("beaker-h2o2").addEventListener("click", function() {
    if (!h2o2Added) {
        pourLiquid("beaker-h2o2", "lightgreen", 40); // 10ml visual
        h2o2Added = true;
    }
    checkReaction();
});

// Check if both reagents added
function checkReaction() {
    if (spinachAdded && h2o2Added) {
        // Simulate oxygen bubbles & volume increase
        setTimeout(() => {
            bubbles.style.display = "block";
            let height = parseInt(cylinderLiquid.style.height);
            let finalHeight = height + 60; // increase volume
            let interval = setInterval(() => {
                if (height < finalHeight) {
                    height++;
                    cylinderLiquid.style.height = height + "px";
                } else {
                    clearInterval(interval);
                }
            }, 30);
        }, 500);
    }
}
