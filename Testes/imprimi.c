int imprimiTab(int opcao){
	FILE *carro, *fabricante, *proprietario, *modelo;
	if(opcao==1){
	carro= fopen("carro.dat", "rb");
	if(arquivo == NULL){
		printf("Nãop foi possível abrir o arquivo Meta.dat\n");
		exit(1);
