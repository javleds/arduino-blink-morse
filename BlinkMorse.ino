const int DOT = 0;
const int LINE = 1;
const int OFF = 2;

const int UNIT = 333;
const int LETTER_SPACE_INTERVAL = 1000;

const int END_PHRASE_BEEPS = 5;
const int END_PHRASE_DELAY = 50;

const int OUTPUT_PIN = 13;

const int DICTIONARY[][4] = {
  {DOT, LINE, OFF, OFF}, // A
  {LINE, DOT, DOT, DOT}, // B
  {LINE, DOT, LINE, DOT}, // C
  {LINE, DOT, DOT, OFF}, // D
  {DOT, OFF, OFF, OFF}, // E
  {DOT, DOT, LINE, DOT}, // F
  {LINE, LINE, DOT, OFF}, // G
  {DOT, DOT, DOT, DOT}, // H
  {DOT, DOT, OFF, OFF}, // I
  {DOT, LINE, LINE, LINE}, // J
  {LINE, DOT, LINE, OFF}, // K
  {DOT, LINE, DOT, DOT}, // L
  {LINE, LINE, OFF, OFF}, // M
  {LINE, DOT, OFF, OFF}, // N
  {LINE, LINE, LINE, OFF}, // O
  {DOT, LINE, LINE, DOT}, // P
  {LINE, LINE, DOT, LINE}, // Q
  {DOT, LINE, DOT, OFF}, // R
  {DOT, DOT, DOT, OFF}, // S
  {LINE, OFF, OFF, OFF}, // T
  {DOT, DOT, LINE, OFF}, // U
  {DOT, DOT, DOT, LINE}, // V
  {DOT, LINE, LINE, OFF}, // W
  {LINE, DOT, DOT, LINE}, // X
  {LINE, DOT, LINE, LINE}, // Y
  {LINE, LINE, DOT, DOT}, // Z
  {OFF, OFF, OFF, OFF} // SPACE
};


int getSequenceIndex(char letter) {
  switch(letter) {
    case 'A': return 0;
    case 'B': return 1;
    case 'C': return 2;
    case 'D': return 3;
    case 'E': return 4;
    case 'F': return 5;
    case 'G': return 6;
    case 'H': return 7;
    case 'I': return 8;
    case 'J': return 9;
    case 'K': return 10;
    case 'L': return 11;
    case 'M': return 12;
    case 'N': return 13;
    case 'O': return 14;
    case 'P': return 15;
    case 'Q': return 16;
    case 'R': return 17;
    case 'S': return 18;
    case 'T': return 19;
    case 'U': return 20;
    case 'V': return 21;
    case 'W': return 22;
    case 'X': return 23;
    case 'Y': return 24;
    case 'Z': return 25;
    default: return 26;
  }
}

void blinkSequence(int sequenceIndex) {
  for (int i = 0; i < 4; i++) {
    if (DICTIONARY[sequenceIndex][i] == DOT) {
      turnOn(UNIT);
      digitalWrite(OUTPUT_PIN, LOW);
      delay(UNIT);

      continue;
    }

    if (DICTIONARY[sequenceIndex][i]== LINE) {
      turnOn(UNIT * 3);
      digitalWrite(OUTPUT_PIN, LOW);
      delay(UNIT);

      continue;
    }
  }
}

void initPhrase() {
  int intermitenceTime = END_PHRASE_DELAY;
  for (int i = 0; i < END_PHRASE_BEEPS; i++) {
    turnOn(intermitenceTime);
    digitalWrite(OUTPUT_PIN, LOW);
    delay(intermitenceTime);
  }
  digitalWrite(OUTPUT_PIN, LOW);
  delay(LETTER_SPACE_INTERVAL);
}

void letterSeparator() {
  digitalWrite(OUTPUT_PIN, LOW);
  delay(LETTER_SPACE_INTERVAL);
}

void turnOn(int milliseconds) {
  digitalWrite(OUTPUT_PIN, HIGH);
  delay(milliseconds);
}

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
  initPhrase();
  String phrase = "Men, I really love to code!";

  int length = phrase.length() + 1;
  char letters[length];
  phrase.toUpperCase();
  phrase.toCharArray(letters, length);

  for (int i = 0; i < phrase.length(); i++) { 
    blinkSequence(
      getSequenceIndex(letters[i])
    );
    letterSeparator();
  }
}
