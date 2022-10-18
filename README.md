# Organização de Estacionamento

### O código desenvolvido foi para resolver o problema proposto a seguir:

1) Suponha que a rotatória do ônibus em frente a UTFPR-PG, seja usada aos
domingos como um estacionamento que guarda até 10 carros. Conforme a Figura.

![Figura 1](https://user-images.githubusercontent.com/44614612/196470893-5b6b389b-33aa-48a6-9363-e0a5260b1d21.png)

Os carros entram conforme indicação das setas em vermelho, e saem conforme
indicação das setas em verde. Se chegar um cliente para retirar um carro que não
esteja estacionado na primeira posição de saída, todos os carros entre o carro do
cliente e a saída serão deslocados para fora do estacionamento, o carro do cliente
sairá do estacionamento e os outros carros voltarão a entrar pela rotatória (seta
vermelha) na mesma ordem que saíram do estacionamento. Observe que sempre
que um carro deixa o estacionamento, todos os carros entre ele e a entrada da
rotatória serão deslocados até o limite da saída (seta verde) de modo que, o tempo
inteiro, todos os espaços vazios estão na entrada do estacionamento, ou seja na
entrada da rotatória (seta vermelha).

Escreva um programa que leia várias entradas. Cada entrada contém um ‘C’, de
chegada, e um ‘P’ de partida, além de um número de placa de licenciamento do
veículo. Presume-se que os carros chegarão e partirão na ordem especificada pela
entrada. O programa deve imprimir uma mensagem cada vez que um carro chegar
ou partir. Quando um carro chegar, a mensagem deverá especificar se existe ou
não vaga para o carro dentro do estacionamento. Se não existir vaga, o carro
esperará pela vaga ou até que uma linha de partida seja lida para o carro. Quando
houver espaço disponível, outra mensagem deverá ser impressa. Quando um carro
partir, a mensagem deverá incluir o número de vezes que o carro foi deslocado
dentro do estacionamento, incluindo a própria partida, mas não a chegada. Esse
número será 0 se o carro for embora a partir da linha de espera.

