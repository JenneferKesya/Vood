#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct{
    int id;
    int *elementos;
    int Produto[TAM];
    int MateriaPrima[TAM];
    int Cor[TAM];
    float Metros[TAM];
    float Diametro[TAM];
    float Preco[TAM];
} Lista;

Lista* criarLista(){
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    if (nova == NULL){
        printf("A lista nao tem espaco\n");
        return NULL;
    }
    
    nova->id = 0;
    nova->elementos = (int*)malloc(TAM * sizeof(int));
    if (nova->elementos == NULL){
        printf("A lista nao tem espaco\n");
        free(nova);
        return NULL;
    }
    
    return nova;
}

Lista* excluirLista(Lista *lista){

    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return NULL;
    }
    
    free(lista->elementos);
    free(lista);
    return NULL;
}

int inserirElemento(Lista *lista, int produto, int materiaPrima, int cor, float metros, float diametro, float preco){
    if (lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
	
    if (lista->id < TAM){
        lista->elementos[lista->id] = lista->id;
        lista->Produto[lista->id] = produto;
        lista->MateriaPrima[lista->id] = materiaPrima;
        lista->Cor[lista->id] = cor;
        lista->Metros[lista->id] = metros;
        lista->Diametro[lista->id] = diametro;
        lista->Preco[lista->id] = preco;
        lista->id++;
        
    } else {
        printf("A lista nao possui mais espaco\n");
        return 0;
    }
    
    return 1;
}

int removerElemento(Lista *lista, int produto){
    int i, j;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    for(i = 0; i < lista->id; ++i){
        if(lista->elementos[i] == produto){
            for(j = i; j < lista->id-1; ++j){
                lista->elementos[j] = lista->elementos[j+1];
                lista->Produto[j] = lista->Produto[j + 1];
                lista->MateriaPrima[j] = lista->MateriaPrima[j + 1];
                lista->Cor[j] = lista->Cor[j + 1];
                lista->Metros[j] = lista->Metros[j + 1];
                lista->Diametro[j] = lista->Diametro[j + 1];
                lista->Preco[j] = lista->Preco[j + 1];
            }
            --(lista->id);
            return 1;
        }
	}
    
}

int inserirElementoInicio(Lista *lista, int produto , int materiaPrima, int cor, float metros, float diametro, float preco){
    int i;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

	if (lista->id < TAM) {
	    for(i = lista->id; i > 0; --i){
	        lista->elementos[i] = lista->elementos[i-1];
	        lista->Produto[i] = lista->Produto[i-1];
	        lista->MateriaPrima[i] = lista->MateriaPrima[i-1];
	        lista->Cor[i] = lista->Cor[i-1];
	        lista->Metros[i] = lista->Metros[i-1];
	        lista->Diametro[i] = lista->Diametro[i-1];
	        lista->Preco[i] = lista->Preco[i-1];
	    }
	    lista->elementos[0] = produto;
	    lista->Produto[0] = produto;
	    lista->MateriaPrima[0] = materiaPrima;
	    lista->Cor[0] = cor;
	    lista->Metros[0] = metros;
	    lista->Diametro[0] = diametro;
	    lista->Preco[0] = preco;
	    ++(lista->id);
	    
	}else{
	    printf("Espaco esgotado\n");
	    return 0;
	}
}

int atualizarElemento(Lista *lista, int produto, int materiaPrima, int cor, float metros, float diametro, float preco){
    int i;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    for(i = 0; i < lista->id; ++i){
        if(lista->Produto[i] == produto){
            lista->MateriaPrima[i] = materiaPrima;
            lista->Cor[i] = cor; 
            lista->Metros[i] = metros;
            lista->Diametro[i] = diametro;
            lista->Preco[i] = preco; // Atualiza o preço
            return 1;
        }
    }
    printf("Produto nao encontrado na lista\n");
    return 0; 
}

int inserirElementoID(Lista *lista, int produto, int cor){
    int i;  
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    
    if(lista->id < TAM){
        if(produto < lista->id){
            for(i = lista->id; i > produto; --i){
                lista->elementos[i] = lista->elementos[i-1];
            }
            lista->elementos[produto] = produto;
            lista->Cor[produto] = cor;
            
        }else{
            printf("Posicao fora o intervalo permitido\n");
        }
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}

void imprimirElementos(Lista *lista){
	int i;
    if (lista == NULL){
        printf("A lista nao foi criada\n");
        return;
    }
    
    if (lista->id < TAM){
    	
	    for (i = 0; i < lista->id; ++i){
	    	printf("Produto: %d\n" , i );
	        printf("Materia Prima - %d: ", lista->MateriaPrima[i]);
	   	   	    switch(lista->MateriaPrima[i]){	
				case 1:
					printf("Couro de Cacto\n");
					break;
				case 2:
					printf("Couro de Maçã\n");
					break;
				case 3:
					printf("Couro de Cogumelo\n");
					break;
				case 4:
					printf("Couro de Borracha Reciclada\n");
					break;
				default:
					break;
				}
			
	        printf("Cor - %d: " , lista->Cor[i] );
		        switch(lista->Cor[i]){	
				case 1:
					printf("Azul\n");
					break;
				case 2:
					printf("Verde\n");
					break;
				case 3:
					printf("Vermelho\n");
					break;
				case 4:
					printf("Preto\n");
					break;
				default:
					break;
				}
			
	        printf("Metros: %.2f\n", lista->Metros[i]);
	        printf("Diametro: %.2f\n", lista->Diametro[i]);
	        printf("Preco: %.2f\n", lista->Preco[i]);
	        printf("\n");
    	}
	
	}else{
		printf("Nao e possivel adicionar mais produtos, tente excluir um item no qual voce nao deseja. \n");
		return;
	}
}

int main(){
    Lista *lista = criarLista();

    int opcao, materialPrima, cor, produto;
    float metros, diametro, preco, totPreco;
    char opcaoExcluir ;

    if (lista != NULL){
	    while (1){
	        printf("--------------------------------- Bem Vindo! ---------------------------------\n");
	        printf("\n");
	        printf("Digite [1] para adicionar um produto que voce deseja\n");
	        printf("Digite [2] para excluir um produto\n");
			printf("Digite [3] para adicionar um produto no inicio da Lista\n");
			printf("Digite [4] para atualizar um produto\n");
			printf("Digite [5] para alterar a cor de um produto\n");
			printf("Digite [6] para excluir sua lista de produtos\n");
	        printf("Digite [0] para sair do programa\n");
	        printf("\n");
	        printf("Opcao desejada: ");
	        scanf("%d", &opcao);
	        getchar();
	        
	        if (opcao == 1){
	            printf("\n");
	            printf("---------------------------------- Produtos ----------------------------------\n");
	            printf("\n");
	            printf("[1]Couro de Cacto\n");
	            printf("Descricao: Feito a partir de folhas de cacto, especificamente do cacto Nopal.\n");
	            printf("Preco: R$ 300 por 1,50 m\n");
	            printf("\n");
	            
				printf("[2]Couro de Maca\n");	
	            printf("Descricao: Produzido a partir de resíduos da indústria de suco de maçã.\n");
	            printf("Preco: R$ 200 por 1,50 m\n");
	            printf("\n");
	            
				printf("[3]Couro de Cogumelo\n");
	            printf("Descricao: Feito a partir do micélio dos cogumelos.\n");
	            printf("Preco: R$ 350 por 1,50 m\n");
	            printf("\n");
	            
	   			printf("[4]Couro de Borracha Reciclada\n");
	            printf("Descricao: Feito a partir de borracha reciclada, como pneus usados.\n");
	            printf("Preco: R$ 150 por 1,50 m\n");
	            printf("\n");
	            
	            printf("Digite o numero do produto que vc quer: ");
	            scanf("%d", &materialPrima);
	            printf("\n");
	            getchar();
	            
	            printf("---------------- Cores ----------------\n");
	            printf("\n");
	            printf("[1]Azul\n");
	            printf("[2]Verde\n");
	            printf("[3]Vermelho\n");
	            printf("[4]Preto\n");
	            printf("\n");    
	            printf("Digite o numero da cor: ");
	            scanf("%d", &cor);
	            printf("\n");
	            getchar();
	            
	            printf("---------------- Comprimentos ----------------\n");
	            printf("\n");
	            printf("Metros: ");
	            scanf("%f", &metros);
	            getchar();
	            printf("Diametro: ");
	            scanf("%f", &diametro);
	            printf("\n");
	            getchar();
	            
	            if (materialPrima == 1){
	                preco = (300/1.50) * metros;
	                printf("Preco: %.2f\n", preco);
	                
	            }else if (materialPrima == 2){
					preco = (200/1.50) * metros;
					printf("Preco: %.2f\n", preco);
					
				}else if (materialPrima == 3){
					preco = (350/1.50) * metros;
					printf("Preco: %.2f\n", preco);
					
		  	    }else{
					preco = (150/1.50) * metros;
					printf("Preco: %.2f\n", preco);  
				  }	
	            
	            inserirElemento(lista, produto, materialPrima, cor, metros, diametro, preco);
	            totPreco += preco;
	            
   				printf("---------------- Nota Fiscal ----------------\n");
	    		printf("\n");
				imprimirElementos(lista);
				printf("Total da Compra: %.2f" , totPreco);
				printf("\n"); 
	              
			}else if (opcao == 2){
				printf("\n");
				printf("---------------- Excluir Produto ----------------\n");
				printf("\n");
				printf("Qual item vc deseja excluir: ");
				scanf("%d" , &produto);
				printf("\n");
				
				removerElemento( lista , produto);
				
		    	printf("---------------- Nota Fiscal ----------------\n");
	    		printf("\n");
				imprimirElementos(lista);
				printf("Total da Compra: %.2f" , totPreco);
				printf("\n");
				
			} else if (opcao == 3){
				printf("\n");
	            printf("---------------------------------- Produtos [Adicionado no Inicio] ----------------------------------\n");
	            printf("\n");
	            printf("[1]Couro de Cacto\n");
	            printf("Descricao: Feito a partir de folhas de cacto, especificamente do cacto Nopal.\n");
	            printf("Preco: R$ 300 por 1,50 m\n");
	            printf("\n");
	            
				printf("[2]Couro de Maca\n");	
	            printf("Descricao: Produzido a partir de resíduos da indústria de suco de maçã.\n");
	            printf("Preco: R$ 200 por 1,50 m\n");
	            printf("\n");
	            
				printf("[3]Couro de Cogumelo\n");
	            printf("Descricao: Feito a partir do micélio dos cogumelos.\n");
	            printf("Preco: R$ 350 por 1,50 m\n");
	            printf("\n");
	            
	   			printf("[4]Couro de Borracha Reciclada\n");
	            printf("Descricao: Feito a partir de borracha reciclada, como pneus usados.\n");
	            printf("Preco: R$ 150 por 1,50 m\n");
	            printf("\n");
	            
	            printf("Digite o numero do produto que vc quer: ");
	            scanf("%d", &materialPrima);
	            printf("\n");
	            getchar();
	            
	            printf("---------------- Cores ----------------\n");
	            printf("\n");
	            printf("[1]Azul\n");
	            printf("[2]Verde\n");
	            printf("[3]Vermelho\n");
	            printf("[4]Preto\n");
	            printf("\n");    
	            printf("Digite o numero da cor: ");
	            scanf("%d", &cor);
	            printf("\n");
	            getchar();
	            
	            printf("---------------- Comprimentos ----------------\n");
	            printf("\n");
	            printf("Metros: ");
	            scanf("%f", &metros);
	            getchar();
	            
	            printf("Diametro: ");
	            scanf("%f", &diametro);
	            printf("\n");
	            getchar();
	            
	            if (materialPrima == 1){
	                preco = (300/1.50) * metros;
	                printf("Preco: %.2f\n", preco);
	                
	            }else if (materialPrima == 2){
					preco = (200/1.50) * metros;
					printf("Preco: %.2f\n", preco);
					
				}else if (materialPrima == 3){
					preco = (350/1.50) * metros;
					printf("Preco: %.2f\n", preco);
					
		  	    }else{
					preco = (150/1.50) * metros;
					printf("Preco: %.2f\n", preco);  
				  }	
	
	           inserirElementoInicio(lista , produto , materialPrima, cor, metros, diametro, preco); 
	           
   	    		printf("---------------- Nota Fiscal ----------------\n");
		    	printf("\n");
				imprimirElementos(lista);
				printf("Total da Compra: %.2f" , totPreco);
				printf("\n");
	            
			}else if (opcao == 4){
				printf("\n");
				printf("---------------- Atualizar Produto ----------------\n");
				printf("\n");
				printf("Qual elemento voce deseja atualizar: ");
				scanf("%d" , &produto);
				
				printf("\n");
	            printf("---------------------------------- Produtos [Atualizar Produto]----------------------------------\n");
	            printf("\n");
	            printf("[1]Couro de Cacto\n");
	            printf("Descricao: Feito a partir de folhas de cacto, especificamente do cacto Nopal.\n");
	            printf("Preco: R$ 300 por 1,50 m\n");
	            printf("\n");
	            
				printf("[2]Couro de Maca\n");	
	            printf("Descricao: Produzido a partir de resíduos da indústria de suco de maçã.\n");
	            printf("Preco: R$ 200 por 1,50 m\n");
	            printf("\n");
	            
				printf("[3]Couro de Cogumelo\n");
	            printf("Descricao: Feito a partir do micélio dos cogumelos.\n");
	            printf("Preco: R$ 350 por 1,50 m\n");
	            printf("\n");
	            
	   			printf("[4]Couro de Borracha Reciclada\n");
	            printf("Descricao: Feito a partir de borracha reciclada, como pneus usados.\n");
	            printf("Preco: R$ 150 por 1,50 m\n");
	            printf("\n");
	            
	            printf("Digite o numero do produto que vc quer: ");
	            scanf("%d", &materialPrima);
	            printf("\n");
	            getchar();
	            
	            printf("---------------- Cores ----------------\n");
	            printf("\n");
	            printf("[1]Azul\n");
	            printf("[2]Verde\n");
	            printf("[3]Vermelho\n");
	            printf("[4]Preto\n");
	            printf("\n");    
	            printf("Digite o numero da cor: ");
	            scanf("%d", &cor);
	            printf("\n");
	            getchar();
	            
	            printf("---------------- Comprimentos ----------------\n");
	            printf("\n");
	            printf("Metros: ");
	            scanf("%f", &metros);
	            getchar();
	            
	            printf("Diametro: ");
	            scanf("%f", &diametro);
	            printf("\n");
	            getchar();
	            
	            if (materialPrima == 1){
	                preco = (300/1.50) * metros;
	                printf("Preco: %.2f\n", preco);
	                
	            }else if (materialPrima == 2){
					preco = (200/1.50) * metros;
					printf("Preco: %.2f\n", preco);
					
				}else if (materialPrima == 3){
					preco = (350/1.50) * metros;
					printf("Preco: %.2f\n", preco);
					
		  	    }else{
					preco = (150/1.50) * metros;
					printf("Preco: %.2f\n", preco);  
				  }	
	
				  atualizarElemento(lista , produto , materialPrima, cor, metros, diametro, preco);
				  
	    		printf("---------------- Nota Fiscal ----------------\n");
		    	printf("\n");
				imprimirElementos(lista);
				printf("Total da Compra: %.2f" , totPreco);
				printf("\n");
	          
			}else if (opcao == 5){
				printf("\n");
				printf("---------------- Atualizar a cor do Produto ----------------\n");
				printf("\n");
				printf("Qual Produto voce deseja atualizar a cor: ");
				scanf("%d" , &produto);
				printf("\n");
				
				printf("---------------- Cores ----------------\n");
	            printf("\n");
	            printf("[1]Azul\n");
	            printf("[2]Verde\n");
	            printf("[3]Vermelho\n");
	            printf("[4]Preto\n");
	            printf("\n");    
	            printf("Digite o numero da cor: ");
	            scanf("%d", &cor);
	            printf("\n");
	            getchar();
	            
	            inserirElementoID( lista, produto, cor);
	            
   				printf("---------------- Nota Fiscal ----------------\n");
	    		printf("\n");
				imprimirElementos(lista);
				printf("Total da Compra: %.2f" , totPreco);
				printf("\n"); 
	        
			}else if (opcao == 6){
				printf("\n");
				printf("---------------- Excluir Pedido ----------------\n");
				printf("\n");
				printf("Tem certeza que deseja excluir o pedido? [S]im ou [N]ao: ");
				scanf("%c" , &opcaoExcluir);
				printf("\n");	
				
				if ((opcaoExcluir == 'S') || (opcaoExcluir == 's')){
					lista = excluirLista(lista);
					printf("Seus pedidos forma excluidos\n");
					
					if (lista == NULL){
						break;
					}
					
				}else{
					printf("A lista nao foi excluida\n");
					printf("\n");
					
	    			printf("---------------- Nota Fiscal ----------------\n");
			    	printf("\n");
					imprimirElementos(lista);
					printf("Total da Compra: %.2f" , totPreco);
					printf("\n");
				
				}
				
			}else{
	            break;
	        } 
	    	
			
		}

}else {
	printf("A lista nao existe");
}	
	
    
    return 0;
}
