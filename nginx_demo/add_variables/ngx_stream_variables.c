
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_stream.h>
#include <nginx.h>

// ...

static ngx_int_t ngx_stream_variable_front4bytes(ngx_stream_session_t *s,
    ngx_stream_variable_value_t *v, uintptr_t data);

static ngx_stream_variable_t  ngx_stream_core_variables[] = {

    // ...

    { ngx_string("front4bytes"), NULL, ngx_stream_variable_front4bytes,
      0, NGX_STREAM_VAR_NOCACHEABLE, 0 },

    { ngx_null_string, NULL, NULL, 0, 0, 0 }
};

// ...

static ngx_int_t
ngx_stream_variable_front4bytes(ngx_stream_session_t *s,
    ngx_stream_variable_value_t *v, uintptr_t data)
{
    ngx_str_t  str;
    const u_char null[4] = {'N', 'U', 'L', 'L'};

    str.len = 4;
    str.data = ngx_pnalloc(s->connection->pool, str.len);
    if (str.data == NULL) {
        return NGX_ERROR;
    }

    int len = 0;
    if (data == 1) {
        len = s->received;
    } else {
        len = s->connection->sent;
    }

#if 0
    printf("data: %*.*s\n", len, len, (char *) s->connection->buffer->pos);
    fflush(stdout);
#endif

    if (len >= 4) {
        ngx_memcpy(str.data, s->connection->buffer->pos, str.len);
    } else {
        ngx_memcpy(str.data, null, str.len);
    }

    v->len = str.len;
    v->valid = 1;
    v->no_cacheable = 0;
    v->not_found = 0;
    v->data = str.data;

    return NGX_OK;
}

// ...

