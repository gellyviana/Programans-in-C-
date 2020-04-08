#!/usr/bin/perl

use POSIX;

@v  = (1,2,3,5,6,7,9,10);
$N  = 8;
$X  = $ARGV[0];

print "INDICE: ";
print buscaB(\@v,0,$N,$X);# Imprime o resultado da função.
print "\n";

sub buscaB {
    my @v     = @{$_[0]};# Recebendo os valores passados pelo parametro de buscaB
    my $E     = $_[1];
    my $D     = $_[2];
    my $X     = $_[3];
    
    my $M = int(($E+$D)/2);# Divide soma dos indices por dois para encontrar o meio do vetor
    
   	if($E<$D){# Caso de parada para as chamadas recursivas.

		if($v[$M] == $X){# Caso em que encontra a chave no vetor, retorna o indice "MEIO".
			return $M;
		}

		elsif($v[$M] > $X){# Caso em que a chave está na primeira parte do vetor.
			return buscaB(\@v,$E, $M, $X);# Faz a chamada recursiva para a primeira parte do vetor.
		}

		elsif($v[$M] < $X){# Caso em que a chave esta na segunda parte do vetor.
			return buscaB(\@v,$M+1, $D, $X);# Faz a chamada recursiva para segunda metade do vetor.
		}

	}else {
		return -1;# Caso nao encontre a chave no vetor.
		}
}
