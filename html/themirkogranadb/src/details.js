window.onload = function () {

    let id = localStorage.getItem("id");

    fetch('https://api.themoviedb.org/3/movie/' + id + '?api_key=7dd3351fd7dcd7de4e6bcdd502b9a4e0&language=it-IT')
        .then(response => response.json())
        .then(result => {
            console.log(result);

            //imposta il titolo della pagina
            document.title = result.original_title;

            //trasforma release_date in una data scritta in forma normale
            var date = new Date(result.release_date);
            var options = { year: 'numeric', month: 'long', day: 'numeric' };
            release_date = date.toLocaleDateString('it-IT', options);



            document.getElementById("original_title").innerHTML = result.title;
            document.getElementById("overview").innerHTML = result.overview;
            document.getElementById("backdrop_path").style.backgroundImage = `url('https://image.tmdb.org/t/p/original${result.backdrop_path}')`;
            document.getElementById("poster_path").src = "https://image.tmdb.org/t/p/original" + result.poster_path;
            document.getElementById("release_date").innerHTML = release_date;
            document.getElementById("vote_average").innerHTML = result.vote_average + "/10, " + result.vote_count + " voti";


        })




}