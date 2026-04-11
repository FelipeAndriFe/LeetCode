//Descrição: Com um array das variações do preço de um stock, calcula o maior lucro comprando em um dia e vendendo em um posterior
//OBS: estoura o limite de tempo

int maxProfit(int* prices, int pricesSize) {
     
    int maxProfit = 0, profit = 0, prev = prices[0] + 1;

    for ( int i = 0; i < pricesSize - 1; i++ ) {
        for ( int j = 1 + i; j < pricesSize; j++ ) {
            if ( prices[i] >= prev ) {
                break;
            }
            profit = prices[j] - prices[i];
            if ( profit > maxProfit ) {
                maxProfit = profit;
            }
        }
        prev = prices[i];
    }

    return maxProfit;
}