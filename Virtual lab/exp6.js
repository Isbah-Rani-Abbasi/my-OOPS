// DOM elements
gsap.to("#h1", {
  x: 400,
  duration: 0.5,
  delay: 0.2,
});

gsap.from("#ins_area", {
  y: 10,
  duration: 0.5,
  delay: 0.2,
  top: 0
});

const beaker = document.getElementById("beaker");
const labArea = document.querySelector(".lab-area");
const milkJar = document.getElementById("milk");
const waterJar = document.getElementById("water");
const milkStream = document.getElementById("milk-stream");
const waterStream = document.getElementById("water-stream");
const milkFill = document.getElementById("milk-fill");
const waterFill = document.getElementById("water-fill");

let milkAdded = false;
let waterAdded = false;
let reactionStarted = false;

// Utility function for overlap check
function isOverlapping(el1, el2) {
  const r1 = el1.getBoundingClientRect();
  const r2 = el2.getBoundingClientRect();
  return !(r1.right < r2.left || r1.left > r2.right || r1.bottom < r2.top || r1.top > r2.bottom);
}

// Drag setup for hydrogen peroxide (milk jar)
Draggable.create(milkJar, {
  bounds: labArea,
  onDragEnd: function () {
    if (isOverlapping(this.target, beaker) && !milkAdded) {
      pourLiquid("milk", this.target);
    } else {
      gsap.to(this.target, { x: 0, y: 0, duration: 0.5 });
    }
  }
});

// Drag setup for spinach paste (water jar)
Draggable.create(waterJar, {
  bounds: labArea,
  onDragEnd: function () {
    if (isOverlapping(this.target, beaker) && !waterAdded) {
      pourLiquid("water", this.target);
    } else {
      gsap.to(this.target, { x: 0, y: 0, duration: 0.5 });
    }
  }
});

// Improved pouring logic
function pourLiquid(type, jar) {
  let stream = type === "milk" ? milkStream : waterStream;
  let fill = type === "milk" ? milkFill : waterFill;

  // Create and position stream properly
  stream.style.position = "absolute";
  stream.style.background = type === "milk" ? "#ffffff" : "#22c55e"; // White for H2O2, Green for spinach
  stream.style.width = "8px";
  stream.style.height = "0px";
  stream.style.borderRadius = "4px";
  stream.style.opacity = "0.9";
  stream.style.zIndex = "5";
  stream.style.boxShadow = type === "milk" ? "0 0 4px rgba(255,255,255,0.5)" : "0 0 4px rgba(34,197,94,0.5)";
  
  // Position stream to fall directly into the cylinder opening
  // Both streams positioned to fall into cylinder center
  if (type === "milk") {
    // Hydrogen peroxide stream - falls into cylinder center
    stream.style.left = "41.2%";
    stream.style.top = "200px";
  } else {
    // Spinach paste stream - falls into cylinder center
    stream.style.left = "41.2%";
    stream.style.top = "300px";
  }
  
  labArea.appendChild(stream);

  // Tilt jar to point toward cylinder - corrected angles
  let tiltAngle;
  if (type === "milk") {
    // Hydrogen peroxide: tilt right to point toward cylinder
    tiltAngle = 45;
  } else {
    // Spinach paste: tilt left to point toward cylinder  
    tiltAngle = -45;
  }
  
  gsap.to(jar, { 
    rotate: tiltAngle, 
    duration: 0.3,
    ease: "power2.out"
  });

  // Stream animation - falls into cylinder
  gsap.fromTo(stream, 
    { height: 0, opacity: 0.8 }, 
    {
      height: type === "milk" ? 180 : 120,
      duration: 1.2,
      ease: "power1.inOut",
      onComplete: () => {
        gsap.to(stream, { 
          opacity: 0, 
          duration: 0.4,
          onComplete: () => stream.remove()
        });
      }
    }
  );

  // Fill cylinder with liquid
  const fillHeight = 50;
  gsap.to(fill, {
    height: `+=${fillHeight}`,
    duration: 1.5,
    delay: 0.5,
    ease: "power2.out",
    onComplete: () => {
      // Change the solution color to green when both are mixed
      if (milkAdded && waterAdded) {
        // Make the solution green (mix of H2O2 and spinach)
        milkFill.style.background = "#22c55e";
        milkFill.style.opacity = "0.7";
        waterFill.style.background = "#22c55e";
        waterFill.style.opacity = "0.7";
      } else if (type === "water") {
        // Spinach paste is green
        waterFill.style.background = "#22c55e";
        waterFill.style.opacity = "0.7";
      }
      
      // Rotate jar back to upright position
      gsap.to(jar, {
        rotate: 0,
        duration: 0.4,
        ease: "power2.out",
        onComplete: () => {
          // Move jar back to original position
          gsap.to(jar, { 
            x: 0, 
            y: 0, 
            duration: 0.6,
            ease: "power2.out"
          });
          
          // Disable further dragging of this jar
          jar.style.pointerEvents = "none";
          jar.style.opacity = "0.6";
          
          // Mark as added and check if reaction should start
          if (type === "milk") {
            milkAdded = true;
          } else {
            waterAdded = true;
          }
          
          // Start reaction when both liquids are added
          if (milkAdded && waterAdded && !reactionStarted) {
            startCatalaseReaction();
          }
        }
      });
    }
  });
}

// Start the catalase reaction (bubble formation and volume increase)
function startCatalaseReaction() {
  reactionStarted = true;
  
  // Show instruction update
  const instructionArea = document.querySelector('.ins-area ul');
  const reactionNote = document.createElement('li');
  reactionNote.innerHTML = '<strong style="color: #10b981;">Reaction started!</strong> Observe bubble formation and volume increase.';
  reactionNote.style.color = '#10b981';
  instructionArea.appendChild(reactionNote);
  
  // Start bubble formation after a short delay
  setTimeout(() => {
    createBubbles();
    // Increase volume due to gas formation
    increaseVolume();
  }, 1000);
}

// Create continuous bubble formation
function createBubbles() {
  const bubbleContainer = document.createElement('div');
  bubbleContainer.id = 'bubble-container';
  bubbleContainer.style.position = 'absolute';
  bubbleContainer.style.bottom = '200px'; // Position above the liquid level
  bubbleContainer.style.left = '40.5%';
  bubbleContainer.style.width = '70px';
  bubbleContainer.style.height = '150px';
  bubbleContainer.style.pointerEvents = 'none';
  bubbleContainer.style.zIndex = '10';
  labArea.appendChild(bubbleContainer);
  
  let bubbleCount = 0;
  const maxBubbles = 20; // More bubbles for dramatic effect
  
  const bubbleInterval = setInterval(() => {
    if (bubbleCount >= maxBubbles) {
      clearInterval(bubbleInterval);
      return;
    }
    
    createSingleBubble(bubbleContainer);
    bubbleCount++;
  }, 150);
  
  // Continue creating occasional bubbles
  setTimeout(() => {
    const slowBubbleInterval = setInterval(() => {
      createSingleBubble(bubbleContainer);
    }, 600);
    
    // Stop after 45 seconds
    setTimeout(() => {
      clearInterval(slowBubbleInterval);
    }, 45000);
  }, 3000);
}

// Create individual bubble
function createSingleBubble(container) {
  const bubble = document.createElement('div');
  bubble.style.position = 'absolute';
  bubble.style.borderRadius = '50%';
  bubble.style.background = 'rgba(255, 255, 255, 0.7)';
  bubble.style.border = '1px solid rgba(255, 255, 255, 0.3)';
  bubble.style.pointerEvents = 'none';
  
  // Random bubble size
  const size = Math.random() * 8 + 4;
  bubble.style.width = `${size}px`;
  bubble.style.height = `${size}px`;
  
  // Random horizontal position within container
  bubble.style.left = `${Math.random() * 40}px`;
  bubble.style.bottom = '0px';
  
  container.appendChild(bubble);
  
  // Animate bubble rising
  gsap.to(bubble, {
    y: -100 - Math.random() * 50,
    x: (Math.random() - 0.5) * 20,
    opacity: 0,
    duration: 2 + Math.random() * 2,
    ease: "power1.out",
    onComplete: () => bubble.remove()
  });
}

// Increase liquid volume due to gas formation
function increaseVolume() {
  // Gradually increase the height significantly to show volume increase from 20ml to 100ml
  gsap.to(milkFill, {
    height: "+=80", // Significant increase
    duration: 4,
    ease: "power2.out"
  });
  
  gsap.to(waterFill, {
    height: "+=80", // Significant increase  
    duration: 4,
    ease: "power2.out"
  });
  
  // Add volume measurement indication
  setTimeout(() => {
    const volumeIndicator = document.createElement('div');
    volumeIndicator.innerHTML = '<strong>Volume Increased Due to O₂ Gas!</strong><br>Initial: 20ml → Final: ~100ml<br><small>Oxygen bubbles increase volume</small>';
    volumeIndicator.style.position = 'absolute';
    volumeIndicator.style.top = '50px';
    volumeIndicator.style.right = '20px';
    volumeIndicator.style.background = 'rgba(16, 185, 129, 0.15)';
    volumeIndicator.style.color = '#10b981';
    volumeIndicator.style.padding = '12px';
    volumeIndicator.style.borderRadius = '10px';
    volumeIndicator.style.border = '2px solid #10b981';
    volumeIndicator.style.fontSize = '13px';
    volumeIndicator.style.textAlign = 'center';
    volumeIndicator.style.fontWeight = 'bold';
    volumeIndicator.style.boxShadow = '0 4px 12px rgba(16, 185, 129, 0.2)';
    labArea.appendChild(volumeIndicator);
    
    // Fade in the indicator
    gsap.fromTo(volumeIndicator, 
      { opacity: 0, scale: 0.8 }, 
      { opacity: 1, scale: 1, duration: 0.6 }
    );
  }, 2000);
}

// Reset functionality (if reset button exists)
function resetExperiment() {
  // Reset all variables
  milkAdded = false;
  waterAdded = false;
  reactionStarted = false;
  
  // Reset liquid fills
  gsap.set(milkFill, { height: 0 });
  gsap.set(waterFill, { height: 0 });
  
  // Re-enable jars
  milkJar.style.pointerEvents = "auto";
  waterJar.style.pointerEvents = "auto";
  milkJar.style.opacity = "1";
  waterJar.style.opacity = "1";
  
  // Reset jar positions and rotations
  gsap.set(milkJar, { x: 0, y: 0, rotation: 0 });
  gsap.set(waterJar, { x: 0, y: 0, rotation: 0 });
  
  // Remove any created elements
  const bubbleContainer = document.getElementById('bubble-container');
  if (bubbleContainer) bubbleContainer.remove();
  
  const volumeIndicator = labArea.querySelector('div[style*="Volume increased"]');
  if (volumeIndicator) volumeIndicator.remove();
  
  // Reset instructions
  const instructionArea = document.querySelector('.ins-area ul');
  const reactionNote = instructionArea.querySelector('li[style*="color: #10b981"]');
  if (reactionNote) reactionNote.remove();
}

// Add event listener for reset button
document.addEventListener('DOMContentLoaded', () => {
  const resetButton = document.querySelector('.reset');
  if (resetButton) {
    resetButton.addEventListener('click', () => {
      resetExperiment();
      // Small delay before page reload to show reset animation
      setTimeout(() => {
        location.reload();
      }, 500);
    });
  }
});

// Add visual feedback for dragging
document.addEventListener('DOMContentLoaded', () => {
  [milkJar, waterJar].forEach(jar => {
    jar.addEventListener('mouseenter', () => {
      if (jar.style.pointerEvents !== 'none') {
        gsap.to(jar, { scale: 1.05, duration: 0.3 });
      }
    });
    
    jar.addEventListener('mouseleave', () => {
      if (jar.style.pointerEvents !== 'none') {
        gsap.to(jar, { scale: 1, duration: 0.3 });
      }
    });
  });
});