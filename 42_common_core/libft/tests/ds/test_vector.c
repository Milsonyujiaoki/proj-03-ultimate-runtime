#include <stdio.h>
#include <assert.h>
#include "libft.h"

/*
** =========================================================
** Tests: t_vector
** =========================================================
*/

static int  s_pass = 0;
static int  s_fail = 0;

#define CHECK(expr) \
    do { \
        if (expr) { printf("  [PASS] %s\n", #expr); s_pass++; } \
        else      { printf("  [FAIL] %s  (line %d)\n", #expr, __LINE__); s_fail++; } \
    } while (0)

/* ── Lifecycle ───────────────────────────────────────── */
static void test_vector_create(void)
{
    t_vector *v;

    printf("--- ft_vector_create ---\n");
    v = ft_vector_create(sizeof(int));
    CHECK(v != NULL);
    CHECK(ft_vector_size(v) == 0);
    CHECK(ft_vector_empty(v) == true);
    ft_vector_destroy(v);
}

/* ── Push / pop ──────────────────────────────────────── */
static void test_vector_push_pop(void)
{
    t_vector    *v;
    int          val;
    int          out;

    printf("--- ft_vector_push / pop ---\n");
    v = ft_vector_create(sizeof(int));
    val = 42;
    CHECK(ft_vector_push(v, &val) == FT_OK);
    CHECK(ft_vector_size(v) == 1);
    val = 100;
    ft_vector_push(v, &val);
    CHECK(ft_vector_size(v) == 2);
    CHECK(ft_vector_pop(v, &out) == FT_OK);
    CHECK(out == 100);
    CHECK(ft_vector_size(v) == 1);
    ft_vector_destroy(v);
}

/* ── Access ──────────────────────────────────────────── */
static void test_vector_access(void)
{
    t_vector    *v;
    int          i;
    int         *p;

    printf("--- ft_vector_get / front / back ---\n");
    v = ft_vector_create(sizeof(int));
    i = 0;
    while (i < 5)
    {
        ft_vector_push(v, &i);
        i++;
    }
    p = (int *)ft_vector_front(v);
    CHECK(*p == 0);
    p = (int *)ft_vector_back(v);
    CHECK(*p == 4);
    p = (int *)ft_vector_get(v, 2);
    CHECK(*p == 2);
    CHECK(ft_vector_get(v, 99) == NULL);
    ft_vector_destroy(v);
}

/* ── Reserve / shrink ────────────────────────────────── */
static void test_vector_reserve(void)
{
    t_vector    *v;
    int          x;

    printf("--- ft_vector_reserve / shrink ---\n");
    v = ft_vector_create(sizeof(int));
    CHECK(ft_vector_reserve(v, 100) == FT_OK);
    CHECK(ft_vector_capacity(v) >= 100);
    x = 7;
    ft_vector_push(v, &x);
    CHECK(ft_vector_shrink(v) == FT_OK);
    CHECK(ft_vector_capacity(v) == 1);
    ft_vector_destroy(v);
}

/* ── Insert / remove at index ────────────────────────── */
static void test_vector_insert_remove(void)
{
    t_vector    *v;
    int          val;
    int         *p;

    printf("--- ft_vector_insert / remove ---\n");
    v = ft_vector_create(sizeof(int));
    val = 1; ft_vector_push(v, &val);
    val = 2; ft_vector_push(v, &val);
    val = 3; ft_vector_push(v, &val);
    /* Insert 99 at index 1 */
    val = 99;
    CHECK(ft_vector_insert(v, 1, &val) == FT_OK);
    CHECK(ft_vector_size(v) == 4);
    p = (int *)ft_vector_get(v, 1);
    CHECK(*p == 99);
    /* Remove index 1 */
    CHECK(ft_vector_remove(v, 1) == FT_OK);
    p = (int *)ft_vector_get(v, 1);
    CHECK(*p == 2);
    ft_vector_destroy(v);
}

/* ── Growth beyond initial capacity ─────────────────── */
static void test_vector_growth(void)
{
    t_vector    *v;
    int          i;
    int         *p;

    printf("--- ft_vector growth ---\n");
    v = ft_vector_create_cap(sizeof(int), 2);
    i = 0;
    while (i < 64)
    {
        CHECK(ft_vector_push(v, &i) == FT_OK);
        i++;
    }
    CHECK(ft_vector_size(v) == 64);
    p = (int *)ft_vector_get(v, 63);
    CHECK(*p == 63);
    ft_vector_destroy(v);
}

/* ── foreach ─────────────────────────────────────────── */
static void visitor_sum(void *elem, void *ctx)
{
    *(int *)ctx += *(int *)elem;
}

static void test_vector_foreach(void)
{
    t_vector    *v;
    int          i;
    int          sum;

    printf("--- ft_vector_foreach ---\n");
    v = ft_vector_create(sizeof(int));
    i = 1;
    while (i <= 5)
    {
        ft_vector_push(v, &i);
        i++;
    }
    sum = 0;
    ft_vector_foreach(v, visitor_sum, &sum);
    CHECK(sum == 15); /* 1+2+3+4+5 */
    ft_vector_destroy(v);
}

/* ── find ────────────────────────────────────────────── */
static t_bool   pred_eq_3(const void *elem, const void *ctx)
{
    (void)ctx;
    return (*(const int *)elem == 3);
}

static void test_vector_find(void)
{
    t_vector    *v;
    int          i;

    printf("--- ft_vector_find ---\n");
    v = ft_vector_create(sizeof(int));
    i = 0;
    while (i < 5)
    {
        ft_vector_push(v, &i);
        i++;
    }
    CHECK(ft_vector_find(v, pred_eq_3, NULL) == 3);
    ft_vector_destroy(v);

    v = ft_vector_create(sizeof(int));
    CHECK(ft_vector_find(v, pred_eq_3, NULL) == FT_ENOTFOUND);
    ft_vector_destroy(v);
}

int main(void)
{
    printf("========================================\n");
    printf("  libft — t_vector tests\n");
    printf("========================================\n");
    test_vector_create();
    test_vector_push_pop();
    test_vector_access();
    test_vector_reserve();
    test_vector_insert_remove();
    test_vector_growth();
    test_vector_foreach();
    test_vector_find();
    printf("----------------------------------------\n");
    printf("  Results: %d passed, %d failed\n", s_pass, s_fail);
    printf("========================================\n");
    return (s_fail > 0 ? 1 : 0);
}
