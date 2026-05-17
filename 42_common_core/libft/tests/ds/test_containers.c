#include <stdio.h>
#include "libft.h"

/*
** =========================================================
** Tests: t_stack + t_queue
** =========================================================
*/

static int  s_pass = 0;
static int  s_fail = 0;

#define CHECK(expr) \
    do { \
        if (expr) { printf("  [PASS] %s\n", #expr); s_pass++; } \
        else      { printf("  [FAIL] %s  (line %d)\n", #expr, __LINE__); s_fail++; } \
    } while (0)

/* ── Stack ───────────────────────────────────────────── */

static void test_stack(void)
{
    t_stack *s;
    int      a = 1, b = 2, c = 3;
    int      out;

    printf("--- ft_stack (LIFO) ---\n");
    s = ft_stack_create(sizeof(int));
    CHECK(ft_stack_empty(s) == true);
    ft_stack_push(s, &a);
    ft_stack_push(s, &b);
    ft_stack_push(s, &c);
    CHECK(ft_stack_size(s) == 3);
    CHECK(*(int *)ft_stack_peek(s) == 3);
    ft_stack_pop(s, &out);
    CHECK(out == 3);
    ft_stack_pop(s, &out);
    CHECK(out == 2);
    ft_stack_pop(s, &out);
    CHECK(out == 1);
    CHECK(ft_stack_empty(s) == true);
    ft_stack_destroy(s);
}

/* ── Queue ───────────────────────────────────────────── */

static void test_queue(void)
{
    t_queue *q;
    int      a = 10, b = 20, c = 30;
    int     *p;

    printf("--- ft_queue (FIFO) ---\n");
    q = ft_queue_create();
    CHECK(ft_queue_empty(q) == true);
    ft_queue_enqueue(q, &a);
    ft_queue_enqueue(q, &b);
    ft_queue_enqueue(q, &c);
    CHECK(ft_queue_size(q) == 3);
    CHECK(*(int *)ft_queue_front(q) == 10);
    p = (int *)ft_queue_dequeue(q);
    CHECK(*p == 10);
    p = (int *)ft_queue_dequeue(q);
    CHECK(*p == 20);
    p = (int *)ft_queue_dequeue(q);
    CHECK(*p == 30);
    CHECK(ft_queue_empty(q) == true);
    CHECK(ft_queue_dequeue(q) == NULL);
    ft_queue_destroy(q);
}

/* ── Arena ───────────────────────────────────────────── */

static void test_arena(void)
{
    t_arena     *a;
    t_arena_mark m;
    int         *p1;
    int         *p2;

    printf("--- ft_arena ---\n");
    a = ft_arena_create(1024);
    CHECK(a != NULL);
    CHECK(ft_arena_used(a) == 0);
    p1 = (int *)ft_arena_alloc(a, sizeof(int));
    CHECK(p1 != NULL);
    *p1 = 42;
    CHECK(*p1 == 42);
    m = ft_arena_mark_save(a);
    p2 = (int *)ft_arena_alloc(a, sizeof(int) * 10);
    CHECK(p2 != NULL);
    CHECK(ft_arena_used(a) > (t_usize)sizeof(int));
    ft_arena_mark_restore(a, m);
    CHECK(ft_arena_used(a) == m);
    ft_arena_reset(a);
    CHECK(ft_arena_used(a) == 0);
    ft_arena_destroy(a);
}

/* ── Pool ────────────────────────────────────────────── */

static void test_pool(void)
{
    t_pool  *p;
    void    *b1;
    void    *b2;
    void    *b3;

    printf("--- ft_pool ---\n");
    p = ft_pool_create(sizeof(int), 3);
    CHECK(p != NULL);
    CHECK(ft_pool_available(p) == 3);
    b1 = ft_pool_alloc(p);
    b2 = ft_pool_alloc(p);
    b3 = ft_pool_alloc(p);
    CHECK(b1 != NULL && b2 != NULL && b3 != NULL);
    CHECK(ft_pool_full(p) == true);
    CHECK(ft_pool_alloc(p) == NULL);
    ft_pool_free(p, b2);
    CHECK(ft_pool_available(p) == 1);
    b2 = ft_pool_alloc(p);
    CHECK(b2 != NULL);
    (void)b3;
    ft_pool_destroy(p);
}

int main(void)
{
    printf("========================================\n");
    printf("  libft — stack / queue / arena / pool\n");
    printf("========================================\n");
    test_stack();
    test_queue();
    test_arena();
    test_pool();
    printf("----------------------------------------\n");
    printf("  Results: %d passed, %d failed\n", s_pass, s_fail);
    printf("========================================\n");
    return (s_fail > 0 ? 1 : 0);
}
