Trabalho Alg III 2016-1

Andrey Ricardo Pimentel e Marcos Didonet Del Fabro

Primeiro Semestre de 2016

1 Introdu¸c˜ao


A banda Vingadora est´a investindo em sua carreira, ap´os lan¸car musicas de
grande sucesso no Carnaval de 2016. Para lan¸car novas m´usicas, eles precisam
complementar seu repertorio musical com mais m´usicas. O letrista da banda ´e
muito esquecido para lembrar das palavras que gostaria de usar nas m´usicas.
Ele s´o que compor em inglˆes e sempre lembra de palavras parecidas mas
nunca da palavra certa. O Violinista da banda, Daniel, viu que poderia ajudar
seu letrista a encontrar palavras parecidas com a que estava pensando utilizando
estruturas de dados conhecidas como arvores digitais. A arvore digital que
Daniel lhe pediu para usar para catalogar palavras foi a TRIE.
O problema a ser resolvido ´e de computar a distˆancia de edi¸c˜ao simplificada
(edit distance) entre duas strings: o n´umero m´ınimo de inser¸c˜oes de caracteres
simples, dele¸c˜oes ou substitui¸c˜oes necess´arias para converter uma string para
outra.

Por exemplo, a distˆancia de edi¸c˜ao entre ”Hello” e ”Jello” ´e 1. A distˆancia
de edi¸c˜ao entre ”good” e ”goodbye” ´e 3. A distˆancia de edi¸c˜ao entre qualquer
palavra e ela mesma ´e 0.
A distˆancia de edi¸c˜ao pode ser usada para prop´ositos tais como sugerindo,
em um corretor ortogr´afico, uma lista de substitutos plaus´ıveis para uma palavra
incorreta. Para cada palavra n˜ao encontrada no dicion´ario (e, portanto, presumivelmente
com erros ortogr´aficos), liste todas as palavras no dicion´ario, que
est˜ao `a uma pequena distˆancia de edi¸c˜ao a partir do erro de ortografia (maximo
3).

2 Especifica¸c˜oes

Daniel ´e exigente e esta anotando instru¸c˜oes especificas do que quer fazer Vamos
ver abaixo o que ele quer fazer:

O programa dever´a ler um arquivo com palavras chamado ***.txt e criar
uma ´arvore TRIE com essas palavras. As palavras 1) n˜ao est˜ao ordenadas
alfabeticamente, 2) as palavras com acento e caracteres especiais (n˜ao letras)
poder˜ao ser ignoradas, 3) n˜ao h´a distin¸c˜ao entre mai´usculas e minusculas, 4) o
1
tamanho do arquivo n˜ao ´e fixo. Um exemplo de arquivo de entrada pode ser
encontrado em: http://www.ime.usp.br/~ueda/br.ispell/pt_BR.aff.gz
O programa dever´a ler um arquivo com as consultas, chamado consultas.txt.
Cada consulta ´e composta de uma palavra e um n´umero que ´e a distˆancia de
edi¸c˜ao. O n´umero m´aximo a ser usado ser´a 3.

Para cada consulta, dever´a realizar uma busca na TRIE, encontrar as palavras
que est˜ao a uma determinada distˆancia de edi¸c˜ao da palavra original e list´a-las
separadas por v´ırgula e na mesma linha. Listar no m´aximo 20 palavras.
O programa ter´a o nome de ”dicionario” e ser´a feito em linguagem C.
O trabalho poder´a ser feito em equipes de at´e 2 (duas) pessoas.

3 Exemplo de execu¸c˜ao

Exemplo de execu¸c˜ao

• Arquivo de entrada com palavras do dicionario:

adriatico
adroaldo
afeganistao
Alasca
Alberta
Albertina
boiaras
boiardes
boiarei
boiareis
boiarem
boiaremo

• Arquivo de entrada com palavras a serem testadas:

adriatico 2

alberta 3

aberta 2

boiada 2

boiada 3


• Arquivo de sa´ıda com o resultado:

adriatico:Adriatico

alberta:Alberta, Albertina

aberta:Alberta

2
boiada:boiaras

boiada:boiaras,boiarei,boiarem

4 Entrega

O trabalho deve ser entregue at´e 23h59m do dia 08 de junho de 2016, contendo
como t´ıtulo do e-mail ”CI057 - Trabalho.2016-1” para o professor de sua turma:

• andrey@inf.ufpr.br

• marcos.ddf@inf.ufpr.br

A data da entrega do trabalho ser´a at´e as 23h59m do dia 08/06/2016. Entregas
fora do prazo ter˜ao desconto na nota por dia de atraso.

5 Detalhes de Entrega

• Deve ser enviado um arquivo compactado tar.gz com, no minimo, os
seguintes arquivos:
– main.c

– dicionario.c

– dicionario.h

– Makefile

– LEIAME (detalhes do trabalho que achar interessante, dificuldades
que teve na implementa¸c˜ao e bugs conhecidos.)

• o trabalho dever´a poder ser compilado no ambiente computacional do dinf.

• a compila¸c˜ao dever´a ser feita com make.

• O arquivo Makefile deve possuir op¸c˜ao clean (apaga todos os arquivos
objeto .o)

• o trabalho dever´a ser executado com a seguinte linha de comando
.\dicionario < entrada.txt > saida.txt

• a verifica¸c˜ao do resultado ser´a feita com
diff saida.txt saida_padrao.txt
3

• O compactado deve possuir o nome como login.tar.gz. Em caso de trabalho
em grupo, deve possuir o login de todos - login1-login2.tar.gz . Apos
descompactar deve gerar uma pasta com o nome do compactado (login ou
login1-login2) com todos os arquivos necess´arios, sem subdiret´orios.
Qualquer duvida, n˜ao hesitem em procurar a monitoria no hor´ario dispon´ıvel
ou mandar e-mail (abovs14@inf.ufpr.br).
