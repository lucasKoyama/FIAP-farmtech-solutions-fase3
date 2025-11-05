# Projeto - Cap 1 - Etapas de uma Máquina Agrícola

## Integrantes:
1. LucasHidekiOliveiraKoyama_RM566925_fase3_cap1
2. EnzoFrançaSader_RM566928_fase3_cap1

Este projeto visa se conectar e carregar dados ao banco de dados oracleDB, neste README.md consta:
1. Um relatório com os passos seguidos;
2. Prints de tela de cada passo e das consultas realizadas;
3. Uso dos arquivos da Fase 2 como base para importação.
4. [video]() explicando todos as etapas realizadas no projeto.

## Faça download do Oracle SQL Developer acessando o site
https://www.oracle.com/database/sqldeveloper/technologies/download/.

## Faça download da versão correspondente para seu sistema operacional. Há versões para o sistema operacional Windows, Linux (x86 e ARM) e Mac OSX. Eventualmente, o site pode pedir que seja feito um cadastro gratuito antes do download.
![downloading for windows 64bits](/images/1_download_oracledb.webp)
    
## Descompacte o arquivo e execute o programa SQLDEVELOPER. Observação: é necessário extrair os arquivos e não apenas abrir o arquivo compactado.
![extracting](/images/2_extract.webp)
![running](/images/3_running.webp)

## Clique em “Nova Conexão” (o ícone + em verde).
![new connection](/images/4_new_connection.webp)

## Estabeleça uma conexão com o banco de dados Oracle:

1. No campo Nome informe um nome qualquer, por exemplo, FIAP.
2. No campo Nome do Usuário informe o seu RM, incluindo as letras RM, por exemplo: RM12345.
3. No campo Senha informe a sua data de nascimento com seis dígitos no formato DDMMYY, por exemplo, se sua data de nascimento for 07 de setembro de 2005 sua senha será 070905. (nesta etapa colocamos outra senha que a FIAP havia enviada em contacto anterior, como descrito no passo 7)
4. Em Nome do Host, informe oracle.fiap.com.br
5. Em Porta, mantenha o número 1521 que já está lá.
6. Em SID, informe ORCL.
7. Clique em Testar. Se receber uma mensagem dizendo que sua conta está bloqueada, entre em contato com o suporte pedindo que desbloqueiem a sua conta. Se receber uma mensagem dizendo que seu usuário ou senha estão inválido, verifique se digitou o seu RM no formato RM12345 (sem espaços e com as letras RM no início) caso esteja correto, entre em contato com o suporte para que resetem sua senha.

![connection settings](/images/5_connection_settings.webp)

## Uma vez conectado ao banco, localize o ícone “Tabelas (Filtrado)”.
![tables icon](/images/6_tables.webp)

## Clique com o botão direito do mouse em “Tabelas (Filtrado)” e selecione “Importa Dados”.
![import data](/images/7_import.webp)

## Clique em “Procurar” e carregue os dados dos seus sensores.
![loading data](/images/8_loading_data.webp)

## Clique em “Próximo”. No campo “Nome da Tabela”, defina um nome para sua tabela. O nome não pode conter espaços, caracteres especiais, deve começar por uma letra e não deve ter mais que 30 dígitos.
![input table name](/images/9_table_name.webp)

## Clique em “Próximo”. Selecione os campos que deseja que sejam importados para o banco de dados, não altere nada caso queira importar todos os dados.
![columns selection](/images/10_columns_selection.webp)

## Clique em “Próximo”. Caso seja necessário, altere o nome das colunas.
![renaming columns](/images/11_renaming_columns.webp)

## Clique em próximo.
![summary of importation](/images/12_importing_summary.webp)

## Clique em “Finalizar” e aguarde a mensagem informando que os dados foram importados com sucesso.
![confirmation of data imported](/images/13_data_import_confirmation.webp)

## Clique em OK e consulte os dados da sua tabela executando o comando SELECT * FROM NOME_DA_SUA_TABELA; onde NOME_DA_SUA_TABELA é o nome que escolheu para a sua tabela. Ctrl+Enter executa o comando.
![query select all](/images/14_query_select_all.webp)

## Agora, você consegue explorar seus dados fazendo consultas neles e o mais legal, estão armazenados no banco da Oracle, em algum lugar do mundo.

```sql
SELECT COUNT(*) AS activated_count
FROM ESP32_DATA
WHERE activated = 1;
```
Contagem de quantas vezes o sensor foi ativado (activated = 1).

![exploring data](/images/15_exploring_data.webp)
