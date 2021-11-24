function getVals(){
  // Get slider values
  var parent = this.parentNode;
  var slides = parent.getElementsByTagName("input");
    var slide1 = parseFloat( slides[0].value );
    var slide2 = parseFloat( slides[1].value );
    var slide3 = parseFloat( slides[2].value );
    var slide4 = parseFloat( slides[3].value );
    // console.log(slides);
  // Neither slider will clip the other, so make sure we determine which is larger
  if( slide1 > slide2 ){ var tmp = slide2; slide2 = slide1; slide1 = tmp; }
  
  var displayElement = parent.getElementsByClassName("rangeValues")[0];
      displayElement.innerHTML = slide1 + " - " + slide2;    
  slides[2].value = slide1;
  slides[3].value = slide2;
  }



function getValsLength(){
  // Get slider values
  var parent = this.parentNode;
  var slides = parent.getElementsByTagName("input");
    var slide1 = parseFloat( slides[0].value );
    // console.log(slides);
  // Neither slider will clip the other, so make sure we determine which is larger  
  var displayElement = parent.getElementsByClassName("rangeLength")[0];
      displayElement.innerHTML = slide1;    
  slides[1].value = slide1;
  }

window.onload = function(){
  // Initialize Sliders
  var sliderSectionsLength = document.getElementsByClassName("range-length");
    for( var x = 0; x < sliderSectionsLength.length; x++ ){
      var slidersLength = sliderSectionsLength[x].getElementsByTagName("input");
      for( var y = 0; y < slidersLength.length; y++ ){
        if( slidersLength[y].type ==="range" ){
          slidersLength[y].oninput = getValsLength;
          // Manually trigger event first time to display values
          slidersLength[y].oninput();
        }
      }
    }
  var sliderSections = document.getElementsByClassName("range-slider");
  for( var x = 0; x < sliderSections.length; x++ ){
    var sliders = sliderSections[x].getElementsByTagName("input");
    for( var y = 0; y < sliders.length; y++ ){
      if( sliders[y].type ==="range" ){
        sliders[y].oninput = getVals;
        // Manually trigger event first time to display values
        sliders[y].oninput();
      }
    }
  }
}