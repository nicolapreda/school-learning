var container = document.getElementById('container1');


function addCircle(){
    //get input1 value
    var input1 = document.getElementById('input1').value;
    var margin_top = 725; 
    var width = 200;
            //clear container
            container.innerHTML = '';

    for(var i = 0; i < input1; i++, margin_top -= 50, width -= 20){
        
        var div = document.createElement('div');
        div.style.marginTop = margin_top + 'px';
        div.style.width = width + 'px';
        div.style.height = '50px';
        div.style.backgroundColor = 'rgb(36, 36, 120)';
        div.style.zindex = '2';
        div.style.borderRadius = '20px';
        div.style.position = 'absolute';
        container.appendChild(div);
    }
}
