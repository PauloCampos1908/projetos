const grid = document.querySelector('.grid');
const timer = document.querySelector('.timer'); 

const characters = [
  'bebe',
  'billy',
  'coragem',
  'finn',
  'jake',
  'minions',
  'morty',
  'ornitorinco',
  'puroosso',
  'rick',
];

// Criação de elementos HTML com classes
const createElement = (tag, className) => {
  const element = document.createElement(tag);
  element.className = className;
  return element;
};

let firstCard = '';
let secondCard = '';
let lockBoard = false;
let timerInterval;

// Verifica o fim do jogo
const checkEndGame = () => {
  const disabledCards = document.querySelectorAll('.disabled-card');

  if (disabledCards.length === 20) {
    clearInterval(timerInterval); // parar o timer
    setTimeout(() => {
      alert(`Parabéns, você ganhou! Seu tempo foi de ${timer.innerHTML} segundos.`);
      location.reload(); // reinicia o jogo
    }, 500);
  }
};

// ver se as cartas combinam
const checkCards = () => {
  const firstCharacter = firstCard.getAttribute('data-character');
  const secondCharacter = secondCard.getAttribute('data-character');

  if (firstCharacter === secondCharacter) {
    firstCard.firstChild.classList.add('disabled-card');
    secondCard.firstChild.classList.add('disabled-card'); // tira as cartas acertadas
    firstCard = '';
    secondCard = '';
    lockBoard = false; // continua o jogo
    checkEndGame();
  } else {
    setTimeout(() => {
      firstCard.classList.remove('reveal-card');
      secondCard.classList.remove('reveal-card');
      firstCard = '';
      secondCard = '';
      lockBoard = false; 
    }, 500);
  }
};

// mostra a carta ao clicar
const revealCard = ({ target }) => {
  if (lockBoard) return;

  const card = target.parentNode;

  if (card.classList.contains('reveal-card')) return;

  card.classList.add('reveal-card');

  if (!firstCard) {
    firstCard = card;
  } else if (!secondCard) {
    secondCard = card;
    lockBoard = true; // nao deixa jogar enquanto ta verificando as cartas
    checkCards();
  }
};

// criação de uma carta com frente e verso
const createCard = (character) => {
  const card = createElement('div', 'card');
  const front = createElement('div', 'face front');
  const back = createElement('div', 'face back');

  // Define a imagem de fundo da frente
  front.style.backgroundImage = `url('../imagens/${character}.jpg')`;

  card.appendChild(front);
  card.appendChild(back);

  card.addEventListener('click', revealCard);
  card.setAttribute('data-character', character);

  return card;
};

// carrega o jogo com cartas aleatorias
const loadGame = () => {
  const duplicateCharacters = [...characters, ...characters];
  const shuffledArray = duplicateCharacters.sort(() => Math.random() - 0.5);

  shuffledArray.forEach((character) => {
    const card = createCard(character);
    grid.appendChild(card);
  });
};

// Inicia o timer
const startTimer = () => {
  let currentTime = 0;

  timerInterval = setInterval(() => {
    currentTime += 1;
    timer.innerHTML = currentTime; //  time
  }, 1000);
};

startTimer();
loadGame();
