//Descrição: em uma matriz de contas, retorna a networth do cliente mais rico

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int wealth = 0, richestWealth = 0, richestIndex = 0;

    for (int i = 0; i < accountsSize; i++){
        for (int j = 0; j < accountsColSize[i]; j++){
            wealth += accounts[i][j];
        }
        if (wealth > richestWealth){
            richestWealth = wealth;
            richestIndex = i;
        }
        wealth = 0;
    }
    return richestWealth;
}