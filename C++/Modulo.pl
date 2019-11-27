package modulo;

use 5.026001;
use strict;
use warnings;

require Exporter;

our @ISA = qw(Exporter);


use constant FACIL => 30;
use constant MEDIO => 50;
use constant DIFICIL => 70;

our %EXPORT_TAGS = ( 'all' => [ qw(
	
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
		ler_arquivo
		escrever_arquivo
        escolher_numero_letras
        escolher_numero_letras_diferentes


        adicionar_palavra
        escolher_dificuldade
        escolher_palavra
        salvar_pontuacao
        ranking
	
);

our $VERSION = '0.01';

#Lendo o arquivo
sub ler_arquivo { 
	my ($filename) = @_;
	open my $in, '<:encoding(UTF-8)', $filename or die "Erro abrindo Arquivo\n";
	local $/ = undef;
	my $all = <$in>;
	close $in or die "Erro fechando Arquivo";
	return $all;
}


#Escrevendo no arquivo
sub escrever_arquivo{ 
    # my $nivel = escolher_dificuldade($palavra);
	my ($filename, $palavra, $dica, $nivel) = @_;
	open my $out, '>:encoding(UTF-8)', $filename or die "Erro gravando Arquivo Alvo\n";
	print $out $palavra $dica $nivel;
	close $out or die "Erro fechando Arquivo Alvo\n";
	return;
}


#numero de letras diferentes
sub escolher_numero_letras_diferentes{
    $palavra = $_[0];
    my $numero = 0;
    my %letras;
    #my $tamanho = length($palavra)

    foreach my $c ($palavra){
        if($numero = 0)
            $letras{$c} = 1;
            $numero++;
        else{
            foreach my $l ($letras){
                if($l != $c ){
                    $numero++;
                    $letras{$c} = $numero;
                }
            }
        }
    }

    return numero;
}

sub vogais{
    $palavra = $_[0];
    $elementos = length($palavra);
    my $numero = 0;

    foreach my $e ($elementos)
        if (($e = 'A')||($e = 'E')||($e = 'I')||($e = 'O')||($e = 'U'))
            numero++;
    return $numero;
}

#escolher dificuldade
sub escolher_dificuldade{
    $palavra = $_[0];
    my $diferentes = escolher_numero_letras_diferentes($palavra);
    my $letras = length($palavra);
    my $vogais = vogais();
    my $valor = ($letras * $diferentes) - ($vogais * 10) ;

    if($valor <= FACIL)
        return "FACIL";
    if($valor <= MEDIO)
        return "MEDIO";

    return "DIFICIL";

}


#Escolher palavra
sub escolher_palavra{
    $dificuldade = $_[0];
    $elementos = $[1];

    my $indice = int(rand($elementos));


    return $palavra;
}



#Salvar pontuacao
sub salvar_pontuacao{ 
	my ($filename, $jogador, $pontos) = @_;
	open my $out, '>:encoding(UTF-8)', $filename or die "Erro gravando Arquivo Alvo\n";
	print $out $jogador $pontos;
	close $out or die "Erro fechando Arquivo Alvo\n";
	return;
}
#Ranking
sub ranking{
    my ($filename) = @_;
	open my $in, '<:encoding(UTF-8)', $filename or die "Erro abrindo Arquivo\n";
	local $/ = undef;
	my $all = <$in>;
	close $in or die "Erro fechando Arquivo";
    return;
}


__END__

