// LED 상태를    토글하는    함수 
function toggleLED(state) {     
    fetch(`/led/${state}`)
        .then(response => response.json())         
        .then(data => {
            if (data.status) {
                alert(data.status);             
            } else if (data.error) {                 
                alert("Error: " + data.error);             }
        }); 
}