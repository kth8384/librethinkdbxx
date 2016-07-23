#ifndef CURSOR_P_H
#define CURSOR_P_H

#include "connection_p.h"

namespace RethinkDB {

class CursorPrivate {
public:
    CursorPrivate(Token&&);
    CursorPrivate(Token&&, Response&&);
    CursorPrivate(Token&&, Datum&&);
    CursorPrivate(Datum&&);

    void add_response(Response&&) const;
    void add_results(Array&&) const;
    void clear_and_read_all() const;
    void convert_single() const;

    mutable bool single = false;
    mutable bool no_more = false;
    mutable size_t index = 0;
    mutable Array buffer;
    Token token;
};

}   // namespace RethinkDB

#endif  // CURSOR_P_H