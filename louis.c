#include <unistd.h>

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

void    ft_affichage(char a, char b, char c)
{
    ft_putchar(a);
    ft_putchar(b);
    ft_putchar(c);
    if  (a == '6' && b == '8' && c == '9')
		return ;
    if  (a != '7')
    {
        ft_putchar(',');
        ft_putchar(' ');
    }
}

void ft_print_comb(void)
{
    int a = '0';
    int b = '0';
    int c = '0';
 
    while   (a != '7' && b != '8' && c != '9')
    {
        b = a + 1;
        while   (b <= '8')
        {
            c = b + 1;
            while   (c <= '9')
            {
                ft_affichage(a, b, c);
                c++;
            }
            b++;
        }
        a++;
    }
}

int main(void)
{
    ft_print_comb();
}