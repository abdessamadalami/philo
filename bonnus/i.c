/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:37:19 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/17 14:46:16 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t semaphore;
int a = 5;

void* routine(void* args) {
    sem_wait(&semaphore);
    a++;
    printf("Hello from process %d %d %d \n", *(int*)args, (int)semaphore,a);
    sem_post(&semaphore);
    exit(0);
  //  free(args);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&semaphore, 0, 4);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        int a = fork();
        if ( a == 0) {
           routine(&i);
        }
    }

    // for (i = 0; i < THREAD_NUM; i++) {
    //     if (pthread_join(th[i], NULL) != 0) {
    //         perror("Failed to join thread");
    //     }
    // }
    sem_destroy(&semaphore);
    return 0;
}