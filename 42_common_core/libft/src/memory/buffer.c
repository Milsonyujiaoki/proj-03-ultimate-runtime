
#include "memory/buffer.h"
#include "memory/memory.h"

/*
** =========================================================
** Byte Buffer — implementation
** =========================================================
*/

#define BUFFER_INIT_CAPACITY  64

static t_ft_status  buffer_grow(t_buffer *buf, t_usize needed)
{
    t_usize new_cap;
    void    *new_data;

    new_cap = buf->capacity ? buf->capacity * 2 : BUFFER_INIT_CAPACITY;
    while (new_cap < needed)
        new_cap *= 2;
    new_data = ft_realloc(buf->data, new_cap);
    if (!new_data)
        return (FT_ENOMEM);
    buf->data = (t_byte *)new_data;
    buf->capacity = new_cap;
    return (FT_OK);
}

t_buffer    *ft_buffer_create(t_usize initial_capacity)
{
    t_buffer    *buf;

    buf = ft_malloc(sizeof(t_buffer));
    if (!buf)
        return (NULL);
    buf->size = 0;
    buf->capacity = initial_capacity ? initial_capacity : BUFFER_INIT_CAPACITY;
    buf->data = ft_malloc(buf->capacity);
    if (!buf->data)
    {
        ft_free(buf);
        return (NULL);
    }
    return (buf);
}

void    ft_buffer_destroy(t_buffer *buf)
{
    if (!buf)
        return ;
    ft_free(buf->data);
    ft_free(buf);
}

t_ft_status ft_buffer_reserve(t_buffer *buf, t_usize min_capacity)
{
    void    *new_data;

    if (!buf)
        return (FT_EINVAL);
    if (min_capacity <= buf->capacity)
        return (FT_OK);
    new_data = ft_realloc(buf->data, min_capacity);
    if (!new_data)
        return (FT_ENOMEM);
    buf->data = (t_byte *)new_data;
    buf->capacity = min_capacity;
    return (FT_OK);
}

t_ft_status ft_buffer_write(t_buffer *buf, const void *data, t_usize size)
{
    if (!buf || !data)
        return (FT_EINVAL);
    if (buf->size + size > buf->capacity)
    {
        if (buffer_grow(buf, buf->size + size) != FT_OK)
            return (FT_ENOMEM);
    }
    ft_memcpy(buf->data + buf->size, data, size);
    buf->size += size;
    return (FT_OK);
}

t_ft_status ft_buffer_write_byte(t_buffer *buf, t_byte b)
{
    return (ft_buffer_write(buf, &b, 1));
}

t_ft_status ft_buffer_write_u16(t_buffer *buf, t_u16 value)
{
    return (ft_buffer_write(buf, &value, sizeof(t_u16)));
}

t_ft_status ft_buffer_write_u32(t_buffer *buf, t_u32 value)
{
    return (ft_buffer_write(buf, &value, sizeof(t_u32)));
}

t_ft_status ft_buffer_write_u64(t_buffer *buf, t_u64 value)
{
    return (ft_buffer_write(buf, &value, sizeof(t_u64)));
}

t_ft_status ft_buffer_write_str(t_buffer *buf, const char *str)
{
    t_usize len;

    if (!buf || !str)
        return (FT_EINVAL);
    len = 0;
    while (str[len])
        len++;
    return (ft_buffer_write(buf, str, len));
}

const t_byte    *ft_buffer_data(const t_buffer *buf)
{
    if (!buf)
        return (NULL);
    return (buf->data);
}

t_usize ft_buffer_size(const t_buffer *buf)
{
    if (!buf)
        return (0);
    return (buf->size);
}

t_bool  ft_buffer_empty(const t_buffer *buf)
{
    return (!buf || buf->size == 0);
}

void    ft_buffer_clear(t_buffer *buf)
{
    if (buf)
        buf->size = 0;
}
