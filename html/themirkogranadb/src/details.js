window.onload = function () {
    const response = localStorage.getItem("response");
    console.log(response);

    let id = localStorage.getItem("id");
    let original_language = localStorage.getItem('original_language');
    let original_title = localStorage.getItem('original_title');
    let overview = localStorage.getItem('overview');
    let backdrop_path = localStorage.getItem('backdrop_path');
    let poster_path = localStorage.getItem('poster_path');
    let release_date = localStorage.getItem('release_date');
    let vote_average = localStorage.getItem('vote_average');
    let vote_count = localStorage.getItem('vote_count');
    let popularity = localStorage.getItem('popularity');

    //trasforma release_date in una data scritta in forma normale
    var date = new Date(release_date);
    var options = { year: 'numeric', month: 'long', day: 'numeric' };
    release_date = date.toLocaleDateString('it-IT', options);


    document.getElementById("original_title").innerHTML = original_title;
    document.getElementById("overview").innerHTML = overview;
    document.getElementById("backdrop_path").style.backgroundImage = `url('https://image.tmdb.org/t/p/original${backdrop_path}')` ;
    document.getElementById("poster_path").src = "https://image.tmdb.org/t/p/original" + poster_path;
    document.getElementById("release_date").innerHTML = release_date;
    document.getElementById("vote_average").innerHTML = vote_average + "/10, " + vote_count + " voti";


    

}