/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 6 - Linked List
*Percobaan        : -
*Hari dan Tanggal : Selasa, 29 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void pembagianMahasiswa(struct Node **head_ref)
{
	struct Node *end = *head_ref;
	struct Node *prev = NULL;
	struct Node *curr = *head_ref;

	while (end->next != NULL)
		end = end->next;

	struct Node *new_end = end;

	while (curr->data % 2 != 0 && curr != end)
	{
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}

	if (curr->data % 2 == 0)
	{
		*head_ref = curr;

		while (curr != end)
		{
			if ((curr->data) % 2 == 0)
			{
				prev = curr;
				curr = curr->next;
			}
			else
			{
				prev->next = curr->next;
				curr->next = NULL;
				new_end->next = curr;
				new_end = curr;
				curr = prev->next;
			}
		}
	}

	else
		prev = curr;

	if (new_end != end && (end->data) % 2 != 0)
	{
		prev->next = end->next;
		end->next = NULL;
		new_end->next = end;
	}
	return;
}

void push(struct Node **head_ref, int new_data)
{
	// Alokasi Node Baru
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Fungsi print node
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node *head = NULL;
	int x, n;

	// Input bagian pertama
	printf("Masukan jumlah mahasiswa : ");
	scanf("%d", &n);

	// Input bagian kedua
	for (int i = 0; i < n; i++)
	{
		printf("Masukan NIM mahasiswa ke-%d : ", i + 1);
		scanf("%d", &x);
		push(&head, x);
	}

	// Output bagian pertama
	printf("\nDaftar NIM mahasiswa yang mengikuti ujian: ");
	printList(head);

	// pemanggilan fungsi pembagian mahasiswa
	pembagianMahasiswa(&head);

	// Output bagian kedua
	printf("\nDaftar NIM mahasiswa setelah dikelompokan: ");
	printList(head);

	return 0;
}
