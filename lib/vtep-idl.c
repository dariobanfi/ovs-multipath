/* Generated automatically -- do not modify!    -*- buffer-read-only: t -*- */

#include <config.h>
#include "lib/vtep-idl.h"
#include <limits.h>
#include "ovs-thread.h"
#include "ovsdb-data.h"
#include "ovsdb-error.h"
#include "util.h"

#ifdef __CHECKER__
/* Sparse dislikes sizeof(bool) ("warning: expression using sizeof bool"). */
enum { sizeof_bool = 1 };
#else
enum { sizeof_bool = sizeof(bool) };
#endif

static bool inited;


static struct vteprec_arp_sources_local *
vteprec_arp_sources_local_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_arp_sources_local, header_) : NULL;
}

static struct vteprec_arp_sources_remote *
vteprec_arp_sources_remote_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_arp_sources_remote, header_) : NULL;
}

static struct vteprec_global *
vteprec_global_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_global, header_) : NULL;
}

static struct vteprec_logical_binding_stats *
vteprec_logical_binding_stats_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_logical_binding_stats, header_) : NULL;
}

static struct vteprec_logical_router *
vteprec_logical_router_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_logical_router, header_) : NULL;
}

static struct vteprec_logical_switch *
vteprec_logical_switch_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_logical_switch, header_) : NULL;
}

static struct vteprec_manager *
vteprec_manager_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_manager, header_) : NULL;
}

static struct vteprec_mcast_macs_local *
vteprec_mcast_macs_local_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_mcast_macs_local, header_) : NULL;
}

static struct vteprec_mcast_macs_remote *
vteprec_mcast_macs_remote_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_mcast_macs_remote, header_) : NULL;
}

static struct vteprec_physical_locator *
vteprec_physical_locator_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_physical_locator, header_) : NULL;
}

static struct vteprec_physical_locator_set *
vteprec_physical_locator_set_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_physical_locator_set, header_) : NULL;
}

static struct vteprec_physical_port *
vteprec_physical_port_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_physical_port, header_) : NULL;
}

static struct vteprec_physical_switch *
vteprec_physical_switch_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_physical_switch, header_) : NULL;
}

static struct vteprec_tunnel *
vteprec_tunnel_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_tunnel, header_) : NULL;
}

static struct vteprec_ucast_macs_local *
vteprec_ucast_macs_local_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_ucast_macs_local, header_) : NULL;
}

static struct vteprec_ucast_macs_remote *
vteprec_ucast_macs_remote_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct vteprec_ucast_macs_remote, header_) : NULL;
}

/* Arp_Sources_Local table. */

static void
vteprec_arp_sources_local_parse_locator(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_arp_sources_local *row = vteprec_arp_sources_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->locator = vteprec_physical_locator_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR], &datum->keys[0].uuid));
    } else {
        row->locator = NULL;
    }
}

static void
vteprec_arp_sources_local_parse_src_mac(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_arp_sources_local *row = vteprec_arp_sources_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->src_mac = datum->keys[0].string;
    } else {
        row->src_mac = "";
    }
}

static void
vteprec_arp_sources_local_unparse_locator(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_arp_sources_local_unparse_src_mac(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_arp_sources_local_init__(struct ovsdb_idl_row *row)
{
    vteprec_arp_sources_local_init(vteprec_arp_sources_local_cast(row));
}

void
vteprec_arp_sources_local_init(struct vteprec_arp_sources_local *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_arp_sources_local *
vteprec_arp_sources_local_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_arp_sources_local_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_ARP_SOURCES_LOCAL], uuid));
}

const struct vteprec_arp_sources_local *
vteprec_arp_sources_local_first(const struct ovsdb_idl *idl)
{
    return vteprec_arp_sources_local_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_ARP_SOURCES_LOCAL]));
}

const struct vteprec_arp_sources_local *
vteprec_arp_sources_local_next(const struct vteprec_arp_sources_local *row)
{
    return vteprec_arp_sources_local_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_arp_sources_local_delete(const struct vteprec_arp_sources_local *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_arp_sources_local *
vteprec_arp_sources_local_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_arp_sources_local_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_ARP_SOURCES_LOCAL], NULL));
}


void
vteprec_arp_sources_local_verify_locator(const struct vteprec_arp_sources_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_arp_sources_local_columns[VTEPREC_ARP_SOURCES_LOCAL_COL_LOCATOR]);
}

void
vteprec_arp_sources_local_verify_src_mac(const struct vteprec_arp_sources_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_arp_sources_local_columns[VTEPREC_ARP_SOURCES_LOCAL_COL_SRC_MAC]);
}

/* Returns the locator column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes locator's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_arp_sources_local_get_locator(const struct vteprec_arp_sources_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_arp_sources_local_col_locator);
}

/* Returns the src_mac column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes src_mac's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_arp_sources_local_get_src_mac(const struct vteprec_arp_sources_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_arp_sources_local_col_src_mac);
}

void
vteprec_arp_sources_local_set_locator(const struct vteprec_arp_sources_local *row, const struct vteprec_physical_locator *locator)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = locator->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_arp_sources_local_columns[VTEPREC_ARP_SOURCES_LOCAL_COL_LOCATOR], &datum);
}

void
vteprec_arp_sources_local_set_src_mac(const struct vteprec_arp_sources_local *row, const char *src_mac)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, src_mac);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_arp_sources_local_columns[VTEPREC_ARP_SOURCES_LOCAL_COL_SRC_MAC], &datum);
}

struct ovsdb_idl_column vteprec_arp_sources_local_columns[VTEPREC_ARP_SOURCES_LOCAL_N_COLUMNS];

static void
vteprec_arp_sources_local_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_arp_sources_local_col_locator. */
    c = &vteprec_arp_sources_local_col_locator;
    c->name = "locator";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Locator";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_arp_sources_local_parse_locator;
    c->unparse = vteprec_arp_sources_local_unparse_locator;

    /* Initialize vteprec_arp_sources_local_col_src_mac. */
    c = &vteprec_arp_sources_local_col_src_mac;
    c->name = "src_mac";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_arp_sources_local_parse_src_mac;
    c->unparse = vteprec_arp_sources_local_unparse_src_mac;
}

/* Arp_Sources_Remote table. */

static void
vteprec_arp_sources_remote_parse_locator(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_arp_sources_remote *row = vteprec_arp_sources_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->locator = vteprec_physical_locator_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR], &datum->keys[0].uuid));
    } else {
        row->locator = NULL;
    }
}

static void
vteprec_arp_sources_remote_parse_src_mac(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_arp_sources_remote *row = vteprec_arp_sources_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->src_mac = datum->keys[0].string;
    } else {
        row->src_mac = "";
    }
}

static void
vteprec_arp_sources_remote_unparse_locator(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_arp_sources_remote_unparse_src_mac(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_arp_sources_remote_init__(struct ovsdb_idl_row *row)
{
    vteprec_arp_sources_remote_init(vteprec_arp_sources_remote_cast(row));
}

void
vteprec_arp_sources_remote_init(struct vteprec_arp_sources_remote *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_arp_sources_remote *
vteprec_arp_sources_remote_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_arp_sources_remote_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_ARP_SOURCES_REMOTE], uuid));
}

const struct vteprec_arp_sources_remote *
vteprec_arp_sources_remote_first(const struct ovsdb_idl *idl)
{
    return vteprec_arp_sources_remote_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_ARP_SOURCES_REMOTE]));
}

const struct vteprec_arp_sources_remote *
vteprec_arp_sources_remote_next(const struct vteprec_arp_sources_remote *row)
{
    return vteprec_arp_sources_remote_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_arp_sources_remote_delete(const struct vteprec_arp_sources_remote *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_arp_sources_remote *
vteprec_arp_sources_remote_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_arp_sources_remote_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_ARP_SOURCES_REMOTE], NULL));
}


void
vteprec_arp_sources_remote_verify_locator(const struct vteprec_arp_sources_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_arp_sources_remote_columns[VTEPREC_ARP_SOURCES_REMOTE_COL_LOCATOR]);
}

void
vteprec_arp_sources_remote_verify_src_mac(const struct vteprec_arp_sources_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_arp_sources_remote_columns[VTEPREC_ARP_SOURCES_REMOTE_COL_SRC_MAC]);
}

/* Returns the locator column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes locator's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_arp_sources_remote_get_locator(const struct vteprec_arp_sources_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_arp_sources_remote_col_locator);
}

/* Returns the src_mac column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes src_mac's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_arp_sources_remote_get_src_mac(const struct vteprec_arp_sources_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_arp_sources_remote_col_src_mac);
}

void
vteprec_arp_sources_remote_set_locator(const struct vteprec_arp_sources_remote *row, const struct vteprec_physical_locator *locator)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = locator->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_arp_sources_remote_columns[VTEPREC_ARP_SOURCES_REMOTE_COL_LOCATOR], &datum);
}

void
vteprec_arp_sources_remote_set_src_mac(const struct vteprec_arp_sources_remote *row, const char *src_mac)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, src_mac);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_arp_sources_remote_columns[VTEPREC_ARP_SOURCES_REMOTE_COL_SRC_MAC], &datum);
}

struct ovsdb_idl_column vteprec_arp_sources_remote_columns[VTEPREC_ARP_SOURCES_REMOTE_N_COLUMNS];

static void
vteprec_arp_sources_remote_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_arp_sources_remote_col_locator. */
    c = &vteprec_arp_sources_remote_col_locator;
    c->name = "locator";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Locator";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_arp_sources_remote_parse_locator;
    c->unparse = vteprec_arp_sources_remote_unparse_locator;

    /* Initialize vteprec_arp_sources_remote_col_src_mac. */
    c = &vteprec_arp_sources_remote_col_src_mac;
    c->name = "src_mac";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_arp_sources_remote_parse_src_mac;
    c->unparse = vteprec_arp_sources_remote_unparse_src_mac;
}

/* Global table. */

static void
vteprec_global_parse_managers(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_global *row = vteprec_global_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->managers = NULL;
    row->n_managers = 0;
    for (i = 0; i < datum->n; i++) {
        struct vteprec_manager *keyRow = vteprec_manager_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_MANAGER], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_managers) {
                row->managers = xmalloc(datum->n * sizeof *row->managers);
            }
            row->managers[row->n_managers] = keyRow;
            row->n_managers++;
        }
    }
}

static void
vteprec_global_parse_switches(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_global *row = vteprec_global_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->switches = NULL;
    row->n_switches = 0;
    for (i = 0; i < datum->n; i++) {
        struct vteprec_physical_switch *keyRow = vteprec_physical_switch_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_SWITCH], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_switches) {
                row->switches = xmalloc(datum->n * sizeof *row->switches);
            }
            row->switches[row->n_switches] = keyRow;
            row->n_switches++;
        }
    }
}

static void
vteprec_global_unparse_managers(struct ovsdb_idl_row *row_)
{
    struct vteprec_global *row = vteprec_global_cast(row_);

    ovs_assert(inited);
    free(row->managers);
}

static void
vteprec_global_unparse_switches(struct ovsdb_idl_row *row_)
{
    struct vteprec_global *row = vteprec_global_cast(row_);

    ovs_assert(inited);
    free(row->switches);
}

static void
vteprec_global_init__(struct ovsdb_idl_row *row)
{
    vteprec_global_init(vteprec_global_cast(row));
}

void
vteprec_global_init(struct vteprec_global *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_global *
vteprec_global_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_global_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_GLOBAL], uuid));
}

const struct vteprec_global *
vteprec_global_first(const struct ovsdb_idl *idl)
{
    return vteprec_global_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_GLOBAL]));
}

const struct vteprec_global *
vteprec_global_next(const struct vteprec_global *row)
{
    return vteprec_global_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_global_delete(const struct vteprec_global *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_global *
vteprec_global_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_global_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_GLOBAL], NULL));
}


void
vteprec_global_verify_managers(const struct vteprec_global *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_global_columns[VTEPREC_GLOBAL_COL_MANAGERS]);
}

void
vteprec_global_verify_switches(const struct vteprec_global *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_global_columns[VTEPREC_GLOBAL_COL_SWITCHES]);
}

/* Returns the managers column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes managers's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_global_get_managers(const struct vteprec_global *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_global_col_managers);
}

/* Returns the switches column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes switches's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_global_get_switches(const struct vteprec_global *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_global_col_switches);
}

void
vteprec_global_set_managers(const struct vteprec_global *row, struct vteprec_manager **managers, size_t n_managers)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_managers;
    datum.keys = n_managers ? xmalloc(n_managers * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (i = 0; i < n_managers; i++) {
        datum.keys[i].uuid = managers[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_global_columns[VTEPREC_GLOBAL_COL_MANAGERS], &datum);
}

void
vteprec_global_set_switches(const struct vteprec_global *row, struct vteprec_physical_switch **switches, size_t n_switches)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_switches;
    datum.keys = n_switches ? xmalloc(n_switches * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (i = 0; i < n_switches; i++) {
        datum.keys[i].uuid = switches[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_global_columns[VTEPREC_GLOBAL_COL_SWITCHES], &datum);
}

struct ovsdb_idl_column vteprec_global_columns[VTEPREC_GLOBAL_N_COLUMNS];

static void
vteprec_global_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_global_col_managers. */
    c = &vteprec_global_col_managers;
    c->name = "managers";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Manager";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_global_parse_managers;
    c->unparse = vteprec_global_unparse_managers;

    /* Initialize vteprec_global_col_switches. */
    c = &vteprec_global_col_switches;
    c->name = "switches";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Switch";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_global_parse_switches;
    c->unparse = vteprec_global_unparse_switches;
}

/* Logical_Binding_Stats table. */

static void
vteprec_logical_binding_stats_parse_bytes_from_local(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_binding_stats *row = vteprec_logical_binding_stats_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->bytes_from_local = datum->keys[0].integer;
    } else {
        row->bytes_from_local = 0;
    }
}

static void
vteprec_logical_binding_stats_parse_bytes_to_local(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_binding_stats *row = vteprec_logical_binding_stats_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->bytes_to_local = datum->keys[0].integer;
    } else {
        row->bytes_to_local = 0;
    }
}

static void
vteprec_logical_binding_stats_parse_packets_from_local(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_binding_stats *row = vteprec_logical_binding_stats_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->packets_from_local = datum->keys[0].integer;
    } else {
        row->packets_from_local = 0;
    }
}

static void
vteprec_logical_binding_stats_parse_packets_to_local(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_binding_stats *row = vteprec_logical_binding_stats_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->packets_to_local = datum->keys[0].integer;
    } else {
        row->packets_to_local = 0;
    }
}

static void
vteprec_logical_binding_stats_unparse_bytes_from_local(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_logical_binding_stats_unparse_bytes_to_local(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_logical_binding_stats_unparse_packets_from_local(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_logical_binding_stats_unparse_packets_to_local(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_logical_binding_stats_init__(struct ovsdb_idl_row *row)
{
    vteprec_logical_binding_stats_init(vteprec_logical_binding_stats_cast(row));
}

void
vteprec_logical_binding_stats_init(struct vteprec_logical_binding_stats *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_logical_binding_stats *
vteprec_logical_binding_stats_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_logical_binding_stats_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_BINDING_STATS], uuid));
}

const struct vteprec_logical_binding_stats *
vteprec_logical_binding_stats_first(const struct ovsdb_idl *idl)
{
    return vteprec_logical_binding_stats_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_BINDING_STATS]));
}

const struct vteprec_logical_binding_stats *
vteprec_logical_binding_stats_next(const struct vteprec_logical_binding_stats *row)
{
    return vteprec_logical_binding_stats_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_logical_binding_stats_delete(const struct vteprec_logical_binding_stats *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_logical_binding_stats *
vteprec_logical_binding_stats_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_logical_binding_stats_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_BINDING_STATS], NULL));
}


void
vteprec_logical_binding_stats_verify_bytes_from_local(const struct vteprec_logical_binding_stats *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_binding_stats_columns[VTEPREC_LOGICAL_BINDING_STATS_COL_BYTES_FROM_LOCAL]);
}

void
vteprec_logical_binding_stats_verify_bytes_to_local(const struct vteprec_logical_binding_stats *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_binding_stats_columns[VTEPREC_LOGICAL_BINDING_STATS_COL_BYTES_TO_LOCAL]);
}

void
vteprec_logical_binding_stats_verify_packets_from_local(const struct vteprec_logical_binding_stats *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_binding_stats_columns[VTEPREC_LOGICAL_BINDING_STATS_COL_PACKETS_FROM_LOCAL]);
}

void
vteprec_logical_binding_stats_verify_packets_to_local(const struct vteprec_logical_binding_stats *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_binding_stats_columns[VTEPREC_LOGICAL_BINDING_STATS_COL_PACKETS_TO_LOCAL]);
}

/* Returns the bytes_from_local column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes bytes_from_local's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_binding_stats_get_bytes_from_local(const struct vteprec_logical_binding_stats *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_binding_stats_col_bytes_from_local);
}

/* Returns the bytes_to_local column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes bytes_to_local's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_binding_stats_get_bytes_to_local(const struct vteprec_logical_binding_stats *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_binding_stats_col_bytes_to_local);
}

/* Returns the packets_from_local column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes packets_from_local's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_binding_stats_get_packets_from_local(const struct vteprec_logical_binding_stats *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_binding_stats_col_packets_from_local);
}

/* Returns the packets_to_local column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes packets_to_local's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_binding_stats_get_packets_to_local(const struct vteprec_logical_binding_stats *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_binding_stats_col_packets_to_local);
}

void
vteprec_logical_binding_stats_set_bytes_from_local(const struct vteprec_logical_binding_stats *row, int64_t bytes_from_local)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.integer = bytes_from_local;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_logical_binding_stats_columns[VTEPREC_LOGICAL_BINDING_STATS_COL_BYTES_FROM_LOCAL], &datum);
}

void
vteprec_logical_binding_stats_set_bytes_to_local(const struct vteprec_logical_binding_stats *row, int64_t bytes_to_local)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.integer = bytes_to_local;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_logical_binding_stats_columns[VTEPREC_LOGICAL_BINDING_STATS_COL_BYTES_TO_LOCAL], &datum);
}

void
vteprec_logical_binding_stats_set_packets_from_local(const struct vteprec_logical_binding_stats *row, int64_t packets_from_local)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.integer = packets_from_local;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_logical_binding_stats_columns[VTEPREC_LOGICAL_BINDING_STATS_COL_PACKETS_FROM_LOCAL], &datum);
}

void
vteprec_logical_binding_stats_set_packets_to_local(const struct vteprec_logical_binding_stats *row, int64_t packets_to_local)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.integer = packets_to_local;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_logical_binding_stats_columns[VTEPREC_LOGICAL_BINDING_STATS_COL_PACKETS_TO_LOCAL], &datum);
}

struct ovsdb_idl_column vteprec_logical_binding_stats_columns[VTEPREC_LOGICAL_BINDING_STATS_N_COLUMNS];

static void
vteprec_logical_binding_stats_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_logical_binding_stats_col_bytes_from_local. */
    c = &vteprec_logical_binding_stats_col_bytes_from_local;
    c->name = "bytes_from_local";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_logical_binding_stats_parse_bytes_from_local;
    c->unparse = vteprec_logical_binding_stats_unparse_bytes_from_local;

    /* Initialize vteprec_logical_binding_stats_col_bytes_to_local. */
    c = &vteprec_logical_binding_stats_col_bytes_to_local;
    c->name = "bytes_to_local";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_logical_binding_stats_parse_bytes_to_local;
    c->unparse = vteprec_logical_binding_stats_unparse_bytes_to_local;

    /* Initialize vteprec_logical_binding_stats_col_packets_from_local. */
    c = &vteprec_logical_binding_stats_col_packets_from_local;
    c->name = "packets_from_local";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_logical_binding_stats_parse_packets_from_local;
    c->unparse = vteprec_logical_binding_stats_unparse_packets_from_local;

    /* Initialize vteprec_logical_binding_stats_col_packets_to_local. */
    c = &vteprec_logical_binding_stats_col_packets_to_local;
    c->name = "packets_to_local";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_logical_binding_stats_parse_packets_to_local;
    c->unparse = vteprec_logical_binding_stats_unparse_packets_to_local;
}

/* Logical_Router table. */

static void
vteprec_logical_router_parse_description(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_router *row = vteprec_logical_router_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->description = datum->keys[0].string;
    } else {
        row->description = "";
    }
}

static void
vteprec_logical_router_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_router *row = vteprec_logical_router_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
vteprec_logical_router_parse_static_routes(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_router *row = vteprec_logical_router_cast(row_);
    size_t i;

    ovs_assert(inited);
    smap_init(&row->static_routes);
    for (i = 0; i < datum->n; i++) {
        smap_add(&row->static_routes,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
vteprec_logical_router_parse_switch_binding(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_router *row = vteprec_logical_router_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->key_switch_binding = NULL;
    row->value_switch_binding = NULL;
    row->n_switch_binding = 0;
    for (i = 0; i < datum->n; i++) {
        struct vteprec_logical_switch *valueRow = vteprec_logical_switch_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_SWITCH], &datum->values[i].uuid));
        if (valueRow) {
            if (!row->n_switch_binding) {
                row->key_switch_binding = xmalloc(datum->n * sizeof *row->key_switch_binding);
                row->value_switch_binding = xmalloc(datum->n * sizeof *row->value_switch_binding);
            }
            row->key_switch_binding[row->n_switch_binding] = datum->keys[i].string;
            row->value_switch_binding[row->n_switch_binding] = valueRow;
            row->n_switch_binding++;
        }
    }
}

static void
vteprec_logical_router_unparse_description(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_logical_router_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_logical_router_unparse_static_routes(struct ovsdb_idl_row *row_)
{
    struct vteprec_logical_router *row = vteprec_logical_router_cast(row_);

    ovs_assert(inited);
    smap_destroy(&row->static_routes);
}

static void
vteprec_logical_router_unparse_switch_binding(struct ovsdb_idl_row *row_)
{
    struct vteprec_logical_router *row = vteprec_logical_router_cast(row_);

    ovs_assert(inited);
    free(row->key_switch_binding);
    free(row->value_switch_binding);
}

static void
vteprec_logical_router_init__(struct ovsdb_idl_row *row)
{
    vteprec_logical_router_init(vteprec_logical_router_cast(row));
}

void
vteprec_logical_router_init(struct vteprec_logical_router *row)
{
    memset(row, 0, sizeof *row); 
    smap_init(&row->static_routes);
}

const struct vteprec_logical_router *
vteprec_logical_router_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_logical_router_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_ROUTER], uuid));
}

const struct vteprec_logical_router *
vteprec_logical_router_first(const struct ovsdb_idl *idl)
{
    return vteprec_logical_router_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_ROUTER]));
}

const struct vteprec_logical_router *
vteprec_logical_router_next(const struct vteprec_logical_router *row)
{
    return vteprec_logical_router_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_logical_router_delete(const struct vteprec_logical_router *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_logical_router *
vteprec_logical_router_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_logical_router_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_ROUTER], NULL));
}


void
vteprec_logical_router_verify_description(const struct vteprec_logical_router *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_router_columns[VTEPREC_LOGICAL_ROUTER_COL_DESCRIPTION]);
}

void
vteprec_logical_router_verify_name(const struct vteprec_logical_router *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_router_columns[VTEPREC_LOGICAL_ROUTER_COL_NAME]);
}

void
vteprec_logical_router_verify_static_routes(const struct vteprec_logical_router *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_router_columns[VTEPREC_LOGICAL_ROUTER_COL_STATIC_ROUTES]);
}

void
vteprec_logical_router_verify_switch_binding(const struct vteprec_logical_router *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_router_columns[VTEPREC_LOGICAL_ROUTER_COL_SWITCH_BINDING]);
}

/* Returns the description column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes description's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_router_get_description(const struct vteprec_logical_router *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_router_col_description);
}

/* Returns the name column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_router_get_name(const struct vteprec_logical_router *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_router_col_name);
}

/* Returns the static_routes column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes static_routes's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_router_get_static_routes(const struct vteprec_logical_router *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_router_col_static_routes);
}

/* Returns the switch_binding column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes switch_binding's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_router_get_switch_binding(const struct vteprec_logical_router *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_router_col_switch_binding);
}

void
vteprec_logical_router_set_description(const struct vteprec_logical_router *row, const char *description)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, description);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_logical_router_columns[VTEPREC_LOGICAL_ROUTER_COL_DESCRIPTION], &datum);
}

void
vteprec_logical_router_set_name(const struct vteprec_logical_router *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_logical_router_columns[VTEPREC_LOGICAL_ROUTER_COL_NAME], &datum);
}

void
vteprec_logical_router_set_static_routes(const struct vteprec_logical_router *row, const struct smap *smap)
{
    struct ovsdb_datum datum;

    ovs_assert(inited);
    if (smap) {
        struct smap_node *node;
        size_t i;

        datum.n = smap_count(smap);
        datum.keys = xmalloc(datum.n * sizeof *datum.keys);
        datum.values = xmalloc(datum.n * sizeof *datum.values);

        i = 0;
        SMAP_FOR_EACH (node, smap) {
            datum.keys[i].string = xstrdup(node->key);
            datum.values[i].string = xstrdup(node->value);
            i++;
        }
        ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &vteprec_logical_router_columns[VTEPREC_LOGICAL_ROUTER_COL_STATIC_ROUTES],
                        &datum);
}


void
vteprec_logical_router_set_switch_binding(const struct vteprec_logical_router *row, char **key_switch_binding, struct vteprec_logical_switch **value_switch_binding, size_t n_switch_binding)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_switch_binding;
    datum.keys = n_switch_binding ? xmalloc(n_switch_binding * sizeof *datum.keys) : NULL;
    datum.values = xmalloc(n_switch_binding * sizeof *datum.values);
    for (i = 0; i < n_switch_binding; i++) {
        datum.keys[i].string = xstrdup(key_switch_binding[i]);
        datum.values[i].uuid = value_switch_binding[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_UUID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_logical_router_columns[VTEPREC_LOGICAL_ROUTER_COL_SWITCH_BINDING], &datum);
}

struct ovsdb_idl_column vteprec_logical_router_columns[VTEPREC_LOGICAL_ROUTER_N_COLUMNS];

static void
vteprec_logical_router_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_logical_router_col_description. */
    c = &vteprec_logical_router_col_description;
    c->name = "description";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_logical_router_parse_description;
    c->unparse = vteprec_logical_router_unparse_description;

    /* Initialize vteprec_logical_router_col_name. */
    c = &vteprec_logical_router_col_name;
    c->name = "name";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_logical_router_parse_name;
    c->unparse = vteprec_logical_router_unparse_name;

    /* Initialize vteprec_logical_router_col_static_routes. */
    c = &vteprec_logical_router_col_static_routes;
    c->name = "static_routes";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_logical_router_parse_static_routes;
    c->unparse = vteprec_logical_router_unparse_static_routes;

    /* Initialize vteprec_logical_router_col_switch_binding. */
    c = &vteprec_logical_router_col_switch_binding;
    c->name = "switch_binding";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_UUID);
    c->type.value.u.uuid.refTableName = "Logical_Switch";
    c->type.value.u.uuid.refType = OVSDB_REF_STRONG;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_logical_router_parse_switch_binding;
    c->unparse = vteprec_logical_router_unparse_switch_binding;
}

/* Logical_Switch table. */

static void
vteprec_logical_switch_parse_description(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_switch *row = vteprec_logical_switch_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->description = datum->keys[0].string;
    } else {
        row->description = "";
    }
}

static void
vteprec_logical_switch_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_switch *row = vteprec_logical_switch_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
vteprec_logical_switch_parse_tunnel_key(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_logical_switch *row = vteprec_logical_switch_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    ovs_assert(inited);
    row->tunnel_key = NULL;
    row->n_tunnel_key = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_tunnel_key) {
            row->tunnel_key = xmalloc(n * sizeof *row->tunnel_key);
        }
        row->tunnel_key[row->n_tunnel_key] = datum->keys[i].integer;
        row->n_tunnel_key++;
    }
}

static void
vteprec_logical_switch_unparse_description(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_logical_switch_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_logical_switch_unparse_tunnel_key(struct ovsdb_idl_row *row_)
{
    struct vteprec_logical_switch *row = vteprec_logical_switch_cast(row_);

    ovs_assert(inited);
    free(row->tunnel_key);
}

static void
vteprec_logical_switch_init__(struct ovsdb_idl_row *row)
{
    vteprec_logical_switch_init(vteprec_logical_switch_cast(row));
}

void
vteprec_logical_switch_init(struct vteprec_logical_switch *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_logical_switch *
vteprec_logical_switch_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_logical_switch_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_SWITCH], uuid));
}

const struct vteprec_logical_switch *
vteprec_logical_switch_first(const struct ovsdb_idl *idl)
{
    return vteprec_logical_switch_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_SWITCH]));
}

const struct vteprec_logical_switch *
vteprec_logical_switch_next(const struct vteprec_logical_switch *row)
{
    return vteprec_logical_switch_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_logical_switch_delete(const struct vteprec_logical_switch *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_logical_switch *
vteprec_logical_switch_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_logical_switch_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_SWITCH], NULL));
}


void
vteprec_logical_switch_verify_description(const struct vteprec_logical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_switch_columns[VTEPREC_LOGICAL_SWITCH_COL_DESCRIPTION]);
}

void
vteprec_logical_switch_verify_name(const struct vteprec_logical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_switch_columns[VTEPREC_LOGICAL_SWITCH_COL_NAME]);
}

void
vteprec_logical_switch_verify_tunnel_key(const struct vteprec_logical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_logical_switch_columns[VTEPREC_LOGICAL_SWITCH_COL_TUNNEL_KEY]);
}

/* Returns the description column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes description's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_switch_get_description(const struct vteprec_logical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_switch_col_description);
}

/* Returns the name column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_switch_get_name(const struct vteprec_logical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_switch_col_name);
}

/* Returns the tunnel_key column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes tunnel_key's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_logical_switch_get_tunnel_key(const struct vteprec_logical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &vteprec_logical_switch_col_tunnel_key);
}

void
vteprec_logical_switch_set_description(const struct vteprec_logical_switch *row, const char *description)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, description);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_logical_switch_columns[VTEPREC_LOGICAL_SWITCH_COL_DESCRIPTION], &datum);
}

void
vteprec_logical_switch_set_name(const struct vteprec_logical_switch *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_logical_switch_columns[VTEPREC_LOGICAL_SWITCH_COL_NAME], &datum);
}

void
vteprec_logical_switch_set_tunnel_key(const struct vteprec_logical_switch *row, const int64_t *tunnel_key, size_t n_tunnel_key)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    if (n_tunnel_key) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *tunnel_key;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_logical_switch_columns[VTEPREC_LOGICAL_SWITCH_COL_TUNNEL_KEY], &datum);
}

struct ovsdb_idl_column vteprec_logical_switch_columns[VTEPREC_LOGICAL_SWITCH_N_COLUMNS];

static void
vteprec_logical_switch_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_logical_switch_col_description. */
    c = &vteprec_logical_switch_col_description;
    c->name = "description";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_logical_switch_parse_description;
    c->unparse = vteprec_logical_switch_unparse_description;

    /* Initialize vteprec_logical_switch_col_name. */
    c = &vteprec_logical_switch_col_name;
    c->name = "name";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_logical_switch_parse_name;
    c->unparse = vteprec_logical_switch_unparse_name;

    /* Initialize vteprec_logical_switch_col_tunnel_key. */
    c = &vteprec_logical_switch_col_tunnel_key;
    c->name = "tunnel_key";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_logical_switch_parse_tunnel_key;
    c->unparse = vteprec_logical_switch_unparse_tunnel_key;
}

/* Manager table. */

static void
vteprec_manager_parse_inactivity_probe(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    ovs_assert(inited);
    row->inactivity_probe = NULL;
    row->n_inactivity_probe = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_inactivity_probe) {
            row->inactivity_probe = xmalloc(n * sizeof *row->inactivity_probe);
        }
        row->inactivity_probe[row->n_inactivity_probe] = datum->keys[i].integer;
        row->n_inactivity_probe++;
    }
}

static void
vteprec_manager_parse_is_connected(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->is_connected = datum->keys[0].boolean;
    } else {
        row->is_connected = false;
    }
}

static void
vteprec_manager_parse_max_backoff(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    ovs_assert(inited);
    row->max_backoff = NULL;
    row->n_max_backoff = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_max_backoff) {
            row->max_backoff = xmalloc(n * sizeof *row->max_backoff);
        }
        row->max_backoff[row->n_max_backoff] = datum->keys[i].integer;
        row->n_max_backoff++;
    }
}

static void
vteprec_manager_parse_other_config(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);
    size_t i;

    ovs_assert(inited);
    smap_init(&row->other_config);
    for (i = 0; i < datum->n; i++) {
        smap_add(&row->other_config,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
vteprec_manager_parse_status(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);
    size_t i;

    ovs_assert(inited);
    smap_init(&row->status);
    for (i = 0; i < datum->n; i++) {
        smap_add(&row->status,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
vteprec_manager_parse_target(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->target = datum->keys[0].string;
    } else {
        row->target = "";
    }
}

static void
vteprec_manager_unparse_inactivity_probe(struct ovsdb_idl_row *row_)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);

    ovs_assert(inited);
    free(row->inactivity_probe);
}

static void
vteprec_manager_unparse_is_connected(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_manager_unparse_max_backoff(struct ovsdb_idl_row *row_)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);

    ovs_assert(inited);
    free(row->max_backoff);
}

static void
vteprec_manager_unparse_other_config(struct ovsdb_idl_row *row_)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);

    ovs_assert(inited);
    smap_destroy(&row->other_config);
}

static void
vteprec_manager_unparse_status(struct ovsdb_idl_row *row_)
{
    struct vteprec_manager *row = vteprec_manager_cast(row_);

    ovs_assert(inited);
    smap_destroy(&row->status);
}

static void
vteprec_manager_unparse_target(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_manager_init__(struct ovsdb_idl_row *row)
{
    vteprec_manager_init(vteprec_manager_cast(row));
}

void
vteprec_manager_init(struct vteprec_manager *row)
{
    memset(row, 0, sizeof *row); 
    smap_init(&row->other_config);
    smap_init(&row->status);
}

const struct vteprec_manager *
vteprec_manager_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_manager_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_MANAGER], uuid));
}

const struct vteprec_manager *
vteprec_manager_first(const struct ovsdb_idl *idl)
{
    return vteprec_manager_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_MANAGER]));
}

const struct vteprec_manager *
vteprec_manager_next(const struct vteprec_manager *row)
{
    return vteprec_manager_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_manager_delete(const struct vteprec_manager *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_manager *
vteprec_manager_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_manager_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_MANAGER], NULL));
}


void
vteprec_manager_verify_inactivity_probe(const struct vteprec_manager *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_INACTIVITY_PROBE]);
}

void
vteprec_manager_verify_is_connected(const struct vteprec_manager *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_IS_CONNECTED]);
}

void
vteprec_manager_verify_max_backoff(const struct vteprec_manager *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_MAX_BACKOFF]);
}

void
vteprec_manager_verify_other_config(const struct vteprec_manager *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_OTHER_CONFIG]);
}

void
vteprec_manager_verify_status(const struct vteprec_manager *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_STATUS]);
}

void
vteprec_manager_verify_target(const struct vteprec_manager *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_TARGET]);
}

/* Returns the inactivity_probe column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes inactivity_probe's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_manager_get_inactivity_probe(const struct vteprec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &vteprec_manager_col_inactivity_probe);
}

/* Returns the is_connected column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes is_connected's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_manager_get_is_connected(const struct vteprec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &vteprec_manager_col_is_connected);
}

/* Returns the max_backoff column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes max_backoff's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_manager_get_max_backoff(const struct vteprec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &vteprec_manager_col_max_backoff);
}

/* Returns the other_config column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes other_config's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_manager_get_other_config(const struct vteprec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_manager_col_other_config);
}

/* Returns the status column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes status's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_manager_get_status(const struct vteprec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_manager_col_status);
}

/* Returns the target column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes target's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_manager_get_target(const struct vteprec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_manager_col_target);
}

void
vteprec_manager_set_inactivity_probe(const struct vteprec_manager *row, const int64_t *inactivity_probe, size_t n_inactivity_probe)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    if (n_inactivity_probe) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *inactivity_probe;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_INACTIVITY_PROBE], &datum);
}

void
vteprec_manager_set_is_connected(const struct vteprec_manager *row, bool is_connected)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.boolean = is_connected;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_IS_CONNECTED], &datum);
}

void
vteprec_manager_set_max_backoff(const struct vteprec_manager *row, const int64_t *max_backoff, size_t n_max_backoff)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    if (n_max_backoff) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *max_backoff;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_MAX_BACKOFF], &datum);
}

void
vteprec_manager_set_other_config(const struct vteprec_manager *row, const struct smap *smap)
{
    struct ovsdb_datum datum;

    ovs_assert(inited);
    if (smap) {
        struct smap_node *node;
        size_t i;

        datum.n = smap_count(smap);
        datum.keys = xmalloc(datum.n * sizeof *datum.keys);
        datum.values = xmalloc(datum.n * sizeof *datum.values);

        i = 0;
        SMAP_FOR_EACH (node, smap) {
            datum.keys[i].string = xstrdup(node->key);
            datum.values[i].string = xstrdup(node->value);
            i++;
        }
        ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &vteprec_manager_columns[VTEPREC_MANAGER_COL_OTHER_CONFIG],
                        &datum);
}


void
vteprec_manager_set_status(const struct vteprec_manager *row, const struct smap *smap)
{
    struct ovsdb_datum datum;

    ovs_assert(inited);
    if (smap) {
        struct smap_node *node;
        size_t i;

        datum.n = smap_count(smap);
        datum.keys = xmalloc(datum.n * sizeof *datum.keys);
        datum.values = xmalloc(datum.n * sizeof *datum.values);

        i = 0;
        SMAP_FOR_EACH (node, smap) {
            datum.keys[i].string = xstrdup(node->key);
            datum.values[i].string = xstrdup(node->value);
            i++;
        }
        ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &vteprec_manager_columns[VTEPREC_MANAGER_COL_STATUS],
                        &datum);
}


void
vteprec_manager_set_target(const struct vteprec_manager *row, const char *target)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, target);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_manager_columns[VTEPREC_MANAGER_COL_TARGET], &datum);
}

struct ovsdb_idl_column vteprec_manager_columns[VTEPREC_MANAGER_N_COLUMNS];

static void
vteprec_manager_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_manager_col_inactivity_probe. */
    c = &vteprec_manager_col_inactivity_probe;
    c->name = "inactivity_probe";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_manager_parse_inactivity_probe;
    c->unparse = vteprec_manager_unparse_inactivity_probe;

    /* Initialize vteprec_manager_col_is_connected. */
    c = &vteprec_manager_col_is_connected;
    c->name = "is_connected";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_manager_parse_is_connected;
    c->unparse = vteprec_manager_unparse_is_connected;

    /* Initialize vteprec_manager_col_max_backoff. */
    c = &vteprec_manager_col_max_backoff;
    c->name = "max_backoff";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(1000);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_manager_parse_max_backoff;
    c->unparse = vteprec_manager_unparse_max_backoff;

    /* Initialize vteprec_manager_col_other_config. */
    c = &vteprec_manager_col_other_config;
    c->name = "other_config";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_manager_parse_other_config;
    c->unparse = vteprec_manager_unparse_other_config;

    /* Initialize vteprec_manager_col_status. */
    c = &vteprec_manager_col_status;
    c->name = "status";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_manager_parse_status;
    c->unparse = vteprec_manager_unparse_status;

    /* Initialize vteprec_manager_col_target. */
    c = &vteprec_manager_col_target;
    c->name = "target";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_manager_parse_target;
    c->unparse = vteprec_manager_unparse_target;
}

/* Mcast_Macs_Local table. */

static void
vteprec_mcast_macs_local_parse_MAC(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_mcast_macs_local *row = vteprec_mcast_macs_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->MAC = datum->keys[0].string;
    } else {
        row->MAC = "";
    }
}

static void
vteprec_mcast_macs_local_parse_ipaddr(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_mcast_macs_local *row = vteprec_mcast_macs_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->ipaddr = datum->keys[0].string;
    } else {
        row->ipaddr = "";
    }
}

static void
vteprec_mcast_macs_local_parse_locator_set(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_mcast_macs_local *row = vteprec_mcast_macs_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->locator_set = vteprec_physical_locator_set_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR_SET], &datum->keys[0].uuid));
    } else {
        row->locator_set = NULL;
    }
}

static void
vteprec_mcast_macs_local_parse_logical_switch(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_mcast_macs_local *row = vteprec_mcast_macs_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->logical_switch = vteprec_logical_switch_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_SWITCH], &datum->keys[0].uuid));
    } else {
        row->logical_switch = NULL;
    }
}

static void
vteprec_mcast_macs_local_unparse_MAC(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_mcast_macs_local_unparse_ipaddr(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_mcast_macs_local_unparse_locator_set(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_mcast_macs_local_unparse_logical_switch(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_mcast_macs_local_init__(struct ovsdb_idl_row *row)
{
    vteprec_mcast_macs_local_init(vteprec_mcast_macs_local_cast(row));
}

void
vteprec_mcast_macs_local_init(struct vteprec_mcast_macs_local *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_mcast_macs_local *
vteprec_mcast_macs_local_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_mcast_macs_local_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_MCAST_MACS_LOCAL], uuid));
}

const struct vteprec_mcast_macs_local *
vteprec_mcast_macs_local_first(const struct ovsdb_idl *idl)
{
    return vteprec_mcast_macs_local_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_MCAST_MACS_LOCAL]));
}

const struct vteprec_mcast_macs_local *
vteprec_mcast_macs_local_next(const struct vteprec_mcast_macs_local *row)
{
    return vteprec_mcast_macs_local_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_mcast_macs_local_delete(const struct vteprec_mcast_macs_local *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_mcast_macs_local *
vteprec_mcast_macs_local_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_mcast_macs_local_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_MCAST_MACS_LOCAL], NULL));
}


void
vteprec_mcast_macs_local_verify_MAC(const struct vteprec_mcast_macs_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_mcast_macs_local_columns[VTEPREC_MCAST_MACS_LOCAL_COL_MAC]);
}

void
vteprec_mcast_macs_local_verify_ipaddr(const struct vteprec_mcast_macs_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_mcast_macs_local_columns[VTEPREC_MCAST_MACS_LOCAL_COL_IPADDR]);
}

void
vteprec_mcast_macs_local_verify_locator_set(const struct vteprec_mcast_macs_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_mcast_macs_local_columns[VTEPREC_MCAST_MACS_LOCAL_COL_LOCATOR_SET]);
}

void
vteprec_mcast_macs_local_verify_logical_switch(const struct vteprec_mcast_macs_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_mcast_macs_local_columns[VTEPREC_MCAST_MACS_LOCAL_COL_LOGICAL_SWITCH]);
}

/* Returns the MAC column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes MAC's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_mcast_macs_local_get_MAC(const struct vteprec_mcast_macs_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_mcast_macs_local_col_MAC);
}

/* Returns the ipaddr column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes ipaddr's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_mcast_macs_local_get_ipaddr(const struct vteprec_mcast_macs_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_mcast_macs_local_col_ipaddr);
}

/* Returns the locator_set column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes locator_set's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_mcast_macs_local_get_locator_set(const struct vteprec_mcast_macs_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_mcast_macs_local_col_locator_set);
}

/* Returns the logical_switch column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes logical_switch's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_mcast_macs_local_get_logical_switch(const struct vteprec_mcast_macs_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_mcast_macs_local_col_logical_switch);
}

void
vteprec_mcast_macs_local_set_MAC(const struct vteprec_mcast_macs_local *row, const char *MAC)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, MAC);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_mcast_macs_local_columns[VTEPREC_MCAST_MACS_LOCAL_COL_MAC], &datum);
}

void
vteprec_mcast_macs_local_set_ipaddr(const struct vteprec_mcast_macs_local *row, const char *ipaddr)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ipaddr);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_mcast_macs_local_columns[VTEPREC_MCAST_MACS_LOCAL_COL_IPADDR], &datum);
}

void
vteprec_mcast_macs_local_set_locator_set(const struct vteprec_mcast_macs_local *row, const struct vteprec_physical_locator_set *locator_set)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = locator_set->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_mcast_macs_local_columns[VTEPREC_MCAST_MACS_LOCAL_COL_LOCATOR_SET], &datum);
}

void
vteprec_mcast_macs_local_set_logical_switch(const struct vteprec_mcast_macs_local *row, const struct vteprec_logical_switch *logical_switch)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = logical_switch->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_mcast_macs_local_columns[VTEPREC_MCAST_MACS_LOCAL_COL_LOGICAL_SWITCH], &datum);
}

struct ovsdb_idl_column vteprec_mcast_macs_local_columns[VTEPREC_MCAST_MACS_LOCAL_N_COLUMNS];

static void
vteprec_mcast_macs_local_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_mcast_macs_local_col_MAC. */
    c = &vteprec_mcast_macs_local_col_MAC;
    c->name = "MAC";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_mcast_macs_local_parse_MAC;
    c->unparse = vteprec_mcast_macs_local_unparse_MAC;

    /* Initialize vteprec_mcast_macs_local_col_ipaddr. */
    c = &vteprec_mcast_macs_local_col_ipaddr;
    c->name = "ipaddr";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_mcast_macs_local_parse_ipaddr;
    c->unparse = vteprec_mcast_macs_local_unparse_ipaddr;

    /* Initialize vteprec_mcast_macs_local_col_locator_set. */
    c = &vteprec_mcast_macs_local_col_locator_set;
    c->name = "locator_set";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Locator_Set";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_mcast_macs_local_parse_locator_set;
    c->unparse = vteprec_mcast_macs_local_unparse_locator_set;

    /* Initialize vteprec_mcast_macs_local_col_logical_switch. */
    c = &vteprec_mcast_macs_local_col_logical_switch;
    c->name = "logical_switch";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Logical_Switch";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_mcast_macs_local_parse_logical_switch;
    c->unparse = vteprec_mcast_macs_local_unparse_logical_switch;
}

/* Mcast_Macs_Remote table. */

static void
vteprec_mcast_macs_remote_parse_MAC(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_mcast_macs_remote *row = vteprec_mcast_macs_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->MAC = datum->keys[0].string;
    } else {
        row->MAC = "";
    }
}

static void
vteprec_mcast_macs_remote_parse_ipaddr(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_mcast_macs_remote *row = vteprec_mcast_macs_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->ipaddr = datum->keys[0].string;
    } else {
        row->ipaddr = "";
    }
}

static void
vteprec_mcast_macs_remote_parse_locator_set(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_mcast_macs_remote *row = vteprec_mcast_macs_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->locator_set = vteprec_physical_locator_set_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR_SET], &datum->keys[0].uuid));
    } else {
        row->locator_set = NULL;
    }
}

static void
vteprec_mcast_macs_remote_parse_logical_switch(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_mcast_macs_remote *row = vteprec_mcast_macs_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->logical_switch = vteprec_logical_switch_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_SWITCH], &datum->keys[0].uuid));
    } else {
        row->logical_switch = NULL;
    }
}

static void
vteprec_mcast_macs_remote_unparse_MAC(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_mcast_macs_remote_unparse_ipaddr(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_mcast_macs_remote_unparse_locator_set(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_mcast_macs_remote_unparse_logical_switch(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_mcast_macs_remote_init__(struct ovsdb_idl_row *row)
{
    vteprec_mcast_macs_remote_init(vteprec_mcast_macs_remote_cast(row));
}

void
vteprec_mcast_macs_remote_init(struct vteprec_mcast_macs_remote *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_mcast_macs_remote *
vteprec_mcast_macs_remote_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_mcast_macs_remote_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_MCAST_MACS_REMOTE], uuid));
}

const struct vteprec_mcast_macs_remote *
vteprec_mcast_macs_remote_first(const struct ovsdb_idl *idl)
{
    return vteprec_mcast_macs_remote_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_MCAST_MACS_REMOTE]));
}

const struct vteprec_mcast_macs_remote *
vteprec_mcast_macs_remote_next(const struct vteprec_mcast_macs_remote *row)
{
    return vteprec_mcast_macs_remote_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_mcast_macs_remote_delete(const struct vteprec_mcast_macs_remote *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_mcast_macs_remote *
vteprec_mcast_macs_remote_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_mcast_macs_remote_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_MCAST_MACS_REMOTE], NULL));
}


void
vteprec_mcast_macs_remote_verify_MAC(const struct vteprec_mcast_macs_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_mcast_macs_remote_columns[VTEPREC_MCAST_MACS_REMOTE_COL_MAC]);
}

void
vteprec_mcast_macs_remote_verify_ipaddr(const struct vteprec_mcast_macs_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_mcast_macs_remote_columns[VTEPREC_MCAST_MACS_REMOTE_COL_IPADDR]);
}

void
vteprec_mcast_macs_remote_verify_locator_set(const struct vteprec_mcast_macs_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_mcast_macs_remote_columns[VTEPREC_MCAST_MACS_REMOTE_COL_LOCATOR_SET]);
}

void
vteprec_mcast_macs_remote_verify_logical_switch(const struct vteprec_mcast_macs_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_mcast_macs_remote_columns[VTEPREC_MCAST_MACS_REMOTE_COL_LOGICAL_SWITCH]);
}

/* Returns the MAC column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes MAC's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_mcast_macs_remote_get_MAC(const struct vteprec_mcast_macs_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_mcast_macs_remote_col_MAC);
}

/* Returns the ipaddr column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes ipaddr's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_mcast_macs_remote_get_ipaddr(const struct vteprec_mcast_macs_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_mcast_macs_remote_col_ipaddr);
}

/* Returns the locator_set column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes locator_set's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_mcast_macs_remote_get_locator_set(const struct vteprec_mcast_macs_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_mcast_macs_remote_col_locator_set);
}

/* Returns the logical_switch column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes logical_switch's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_mcast_macs_remote_get_logical_switch(const struct vteprec_mcast_macs_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_mcast_macs_remote_col_logical_switch);
}

void
vteprec_mcast_macs_remote_set_MAC(const struct vteprec_mcast_macs_remote *row, const char *MAC)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, MAC);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_mcast_macs_remote_columns[VTEPREC_MCAST_MACS_REMOTE_COL_MAC], &datum);
}

void
vteprec_mcast_macs_remote_set_ipaddr(const struct vteprec_mcast_macs_remote *row, const char *ipaddr)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ipaddr);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_mcast_macs_remote_columns[VTEPREC_MCAST_MACS_REMOTE_COL_IPADDR], &datum);
}

void
vteprec_mcast_macs_remote_set_locator_set(const struct vteprec_mcast_macs_remote *row, const struct vteprec_physical_locator_set *locator_set)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = locator_set->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_mcast_macs_remote_columns[VTEPREC_MCAST_MACS_REMOTE_COL_LOCATOR_SET], &datum);
}

void
vteprec_mcast_macs_remote_set_logical_switch(const struct vteprec_mcast_macs_remote *row, const struct vteprec_logical_switch *logical_switch)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = logical_switch->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_mcast_macs_remote_columns[VTEPREC_MCAST_MACS_REMOTE_COL_LOGICAL_SWITCH], &datum);
}

struct ovsdb_idl_column vteprec_mcast_macs_remote_columns[VTEPREC_MCAST_MACS_REMOTE_N_COLUMNS];

static void
vteprec_mcast_macs_remote_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_mcast_macs_remote_col_MAC. */
    c = &vteprec_mcast_macs_remote_col_MAC;
    c->name = "MAC";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_mcast_macs_remote_parse_MAC;
    c->unparse = vteprec_mcast_macs_remote_unparse_MAC;

    /* Initialize vteprec_mcast_macs_remote_col_ipaddr. */
    c = &vteprec_mcast_macs_remote_col_ipaddr;
    c->name = "ipaddr";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_mcast_macs_remote_parse_ipaddr;
    c->unparse = vteprec_mcast_macs_remote_unparse_ipaddr;

    /* Initialize vteprec_mcast_macs_remote_col_locator_set. */
    c = &vteprec_mcast_macs_remote_col_locator_set;
    c->name = "locator_set";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Locator_Set";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_mcast_macs_remote_parse_locator_set;
    c->unparse = vteprec_mcast_macs_remote_unparse_locator_set;

    /* Initialize vteprec_mcast_macs_remote_col_logical_switch. */
    c = &vteprec_mcast_macs_remote_col_logical_switch;
    c->name = "logical_switch";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Logical_Switch";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_mcast_macs_remote_parse_logical_switch;
    c->unparse = vteprec_mcast_macs_remote_unparse_logical_switch;
}

/* Physical_Locator table. */

static void
vteprec_physical_locator_parse_dst_ip(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_locator *row = vteprec_physical_locator_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->dst_ip = datum->keys[0].string;
    } else {
        row->dst_ip = "";
    }
}

static void
vteprec_physical_locator_parse_encapsulation_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_locator *row = vteprec_physical_locator_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->encapsulation_type = datum->keys[0].string;
    } else {
        row->encapsulation_type = "";
    }
}

static void
vteprec_physical_locator_unparse_dst_ip(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_physical_locator_unparse_encapsulation_type(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_physical_locator_init__(struct ovsdb_idl_row *row)
{
    vteprec_physical_locator_init(vteprec_physical_locator_cast(row));
}

void
vteprec_physical_locator_init(struct vteprec_physical_locator *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_physical_locator *
vteprec_physical_locator_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_physical_locator_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR], uuid));
}

const struct vteprec_physical_locator *
vteprec_physical_locator_first(const struct ovsdb_idl *idl)
{
    return vteprec_physical_locator_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR]));
}

const struct vteprec_physical_locator *
vteprec_physical_locator_next(const struct vteprec_physical_locator *row)
{
    return vteprec_physical_locator_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_physical_locator_delete(const struct vteprec_physical_locator *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_physical_locator *
vteprec_physical_locator_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_physical_locator_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR], NULL));
}


void
vteprec_physical_locator_verify_dst_ip(const struct vteprec_physical_locator *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_locator_columns[VTEPREC_PHYSICAL_LOCATOR_COL_DST_IP]);
}

void
vteprec_physical_locator_verify_encapsulation_type(const struct vteprec_physical_locator *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_locator_columns[VTEPREC_PHYSICAL_LOCATOR_COL_ENCAPSULATION_TYPE]);
}

/* Returns the dst_ip column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes dst_ip's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_locator_get_dst_ip(const struct vteprec_physical_locator *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_locator_col_dst_ip);
}

/* Returns the encapsulation_type column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes encapsulation_type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_locator_get_encapsulation_type(const struct vteprec_physical_locator *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_locator_col_encapsulation_type);
}

void
vteprec_physical_locator_set_dst_ip(const struct vteprec_physical_locator *row, const char *dst_ip)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, dst_ip);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_physical_locator_columns[VTEPREC_PHYSICAL_LOCATOR_COL_DST_IP], &datum);
}

void
vteprec_physical_locator_set_encapsulation_type(const struct vteprec_physical_locator *row, const char *encapsulation_type)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, encapsulation_type);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_physical_locator_columns[VTEPREC_PHYSICAL_LOCATOR_COL_ENCAPSULATION_TYPE], &datum);
}

struct ovsdb_idl_column vteprec_physical_locator_columns[VTEPREC_PHYSICAL_LOCATOR_N_COLUMNS];

static void
vteprec_physical_locator_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_physical_locator_col_dst_ip. */
    c = &vteprec_physical_locator_col_dst_ip;
    c->name = "dst_ip";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = false;
    c->parse = vteprec_physical_locator_parse_dst_ip;
    c->unparse = vteprec_physical_locator_unparse_dst_ip;

    /* Initialize vteprec_physical_locator_col_encapsulation_type. */
    c = &vteprec_physical_locator_col_encapsulation_type;
    c->name = "encapsulation_type";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 1;
    c->type.key.enum_->keys = xmalloc(1 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("vxlan_over_ipv4");
    c->type.key.enum_->values = NULL;
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = false;
    c->parse = vteprec_physical_locator_parse_encapsulation_type;
    c->unparse = vteprec_physical_locator_unparse_encapsulation_type;
}

/* Physical_Locator_Set table. */

static void
vteprec_physical_locator_set_parse_locators(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_locator_set *row = vteprec_physical_locator_set_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->locators = NULL;
    row->n_locators = 0;
    for (i = 0; i < datum->n; i++) {
        struct vteprec_physical_locator *keyRow = vteprec_physical_locator_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_locators) {
                row->locators = xmalloc(datum->n * sizeof *row->locators);
            }
            row->locators[row->n_locators] = keyRow;
            row->n_locators++;
        }
    }
}

static void
vteprec_physical_locator_set_unparse_locators(struct ovsdb_idl_row *row_)
{
    struct vteprec_physical_locator_set *row = vteprec_physical_locator_set_cast(row_);

    ovs_assert(inited);
    free(row->locators);
}

static void
vteprec_physical_locator_set_init__(struct ovsdb_idl_row *row)
{
    vteprec_physical_locator_set_init(vteprec_physical_locator_set_cast(row));
}

void
vteprec_physical_locator_set_init(struct vteprec_physical_locator_set *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_physical_locator_set *
vteprec_physical_locator_set_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_physical_locator_set_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR_SET], uuid));
}

const struct vteprec_physical_locator_set *
vteprec_physical_locator_set_first(const struct ovsdb_idl *idl)
{
    return vteprec_physical_locator_set_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR_SET]));
}

const struct vteprec_physical_locator_set *
vteprec_physical_locator_set_next(const struct vteprec_physical_locator_set *row)
{
    return vteprec_physical_locator_set_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_physical_locator_set_delete(const struct vteprec_physical_locator_set *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_physical_locator_set *
vteprec_physical_locator_set_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_physical_locator_set_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR_SET], NULL));
}


void
vteprec_physical_locator_set_verify_locators(const struct vteprec_physical_locator_set *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_locator_set_columns[VTEPREC_PHYSICAL_LOCATOR_SET_COL_LOCATORS]);
}

/* Returns the locators column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes locators's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_locator_set_get_locators(const struct vteprec_physical_locator_set *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_locator_set_col_locators);
}

void
vteprec_physical_locator_set_set_locators(const struct vteprec_physical_locator_set *row, struct vteprec_physical_locator **locators, size_t n_locators)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_locators;
    datum.keys = n_locators ? xmalloc(n_locators * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (i = 0; i < n_locators; i++) {
        datum.keys[i].uuid = locators[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_physical_locator_set_columns[VTEPREC_PHYSICAL_LOCATOR_SET_COL_LOCATORS], &datum);
}

struct ovsdb_idl_column vteprec_physical_locator_set_columns[VTEPREC_PHYSICAL_LOCATOR_SET_N_COLUMNS];

static void
vteprec_physical_locator_set_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_physical_locator_set_col_locators. */
    c = &vteprec_physical_locator_set_col_locators;
    c->name = "locators";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Locator";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = UINT_MAX;
    c->mutable = false;
    c->parse = vteprec_physical_locator_set_parse_locators;
    c->unparse = vteprec_physical_locator_set_unparse_locators;
}

/* Physical_Port table. */

static void
vteprec_physical_port_parse_description(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_port *row = vteprec_physical_port_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->description = datum->keys[0].string;
    } else {
        row->description = "";
    }
}

static void
vteprec_physical_port_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_port *row = vteprec_physical_port_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
vteprec_physical_port_parse_port_fault_status(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_port *row = vteprec_physical_port_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->port_fault_status = NULL;
    row->n_port_fault_status = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_port_fault_status) {
            row->port_fault_status = xmalloc(datum->n * sizeof *row->port_fault_status);
        }
        row->port_fault_status[row->n_port_fault_status] = datum->keys[i].string;
        row->n_port_fault_status++;
    }
}

static void
vteprec_physical_port_parse_vlan_bindings(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_port *row = vteprec_physical_port_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->key_vlan_bindings = NULL;
    row->value_vlan_bindings = NULL;
    row->n_vlan_bindings = 0;
    for (i = 0; i < datum->n; i++) {
        struct vteprec_logical_switch *valueRow = vteprec_logical_switch_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_SWITCH], &datum->values[i].uuid));
        if (valueRow) {
            if (!row->n_vlan_bindings) {
                row->key_vlan_bindings = xmalloc(datum->n * sizeof *row->key_vlan_bindings);
                row->value_vlan_bindings = xmalloc(datum->n * sizeof *row->value_vlan_bindings);
            }
            row->key_vlan_bindings[row->n_vlan_bindings] = datum->keys[i].integer;
            row->value_vlan_bindings[row->n_vlan_bindings] = valueRow;
            row->n_vlan_bindings++;
        }
    }
}

static void
vteprec_physical_port_parse_vlan_stats(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_port *row = vteprec_physical_port_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->key_vlan_stats = NULL;
    row->value_vlan_stats = NULL;
    row->n_vlan_stats = 0;
    for (i = 0; i < datum->n; i++) {
        struct vteprec_logical_binding_stats *valueRow = vteprec_logical_binding_stats_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_BINDING_STATS], &datum->values[i].uuid));
        if (valueRow) {
            if (!row->n_vlan_stats) {
                row->key_vlan_stats = xmalloc(datum->n * sizeof *row->key_vlan_stats);
                row->value_vlan_stats = xmalloc(datum->n * sizeof *row->value_vlan_stats);
            }
            row->key_vlan_stats[row->n_vlan_stats] = datum->keys[i].integer;
            row->value_vlan_stats[row->n_vlan_stats] = valueRow;
            row->n_vlan_stats++;
        }
    }
}

static void
vteprec_physical_port_unparse_description(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_physical_port_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_physical_port_unparse_port_fault_status(struct ovsdb_idl_row *row_)
{
    struct vteprec_physical_port *row = vteprec_physical_port_cast(row_);

    ovs_assert(inited);
    free(row->port_fault_status);
}

static void
vteprec_physical_port_unparse_vlan_bindings(struct ovsdb_idl_row *row_)
{
    struct vteprec_physical_port *row = vteprec_physical_port_cast(row_);

    ovs_assert(inited);
    free(row->key_vlan_bindings);
    free(row->value_vlan_bindings);
}

static void
vteprec_physical_port_unparse_vlan_stats(struct ovsdb_idl_row *row_)
{
    struct vteprec_physical_port *row = vteprec_physical_port_cast(row_);

    ovs_assert(inited);
    free(row->key_vlan_stats);
    free(row->value_vlan_stats);
}

static void
vteprec_physical_port_init__(struct ovsdb_idl_row *row)
{
    vteprec_physical_port_init(vteprec_physical_port_cast(row));
}

void
vteprec_physical_port_init(struct vteprec_physical_port *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_physical_port *
vteprec_physical_port_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_physical_port_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_PORT], uuid));
}

const struct vteprec_physical_port *
vteprec_physical_port_first(const struct ovsdb_idl *idl)
{
    return vteprec_physical_port_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_PORT]));
}

const struct vteprec_physical_port *
vteprec_physical_port_next(const struct vteprec_physical_port *row)
{
    return vteprec_physical_port_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_physical_port_delete(const struct vteprec_physical_port *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_physical_port *
vteprec_physical_port_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_physical_port_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_PORT], NULL));
}


void
vteprec_physical_port_verify_description(const struct vteprec_physical_port *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_DESCRIPTION]);
}

void
vteprec_physical_port_verify_name(const struct vteprec_physical_port *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_NAME]);
}

void
vteprec_physical_port_verify_port_fault_status(const struct vteprec_physical_port *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_PORT_FAULT_STATUS]);
}

void
vteprec_physical_port_verify_vlan_bindings(const struct vteprec_physical_port *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_VLAN_BINDINGS]);
}

void
vteprec_physical_port_verify_vlan_stats(const struct vteprec_physical_port *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_VLAN_STATS]);
}

/* Returns the description column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes description's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_port_get_description(const struct vteprec_physical_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_port_col_description);
}

/* Returns the name column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_port_get_name(const struct vteprec_physical_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_port_col_name);
}

/* Returns the port_fault_status column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes port_fault_status's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_port_get_port_fault_status(const struct vteprec_physical_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_port_col_port_fault_status);
}

/* Returns the vlan_bindings column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * 'value_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes vlan_bindings's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_port_get_vlan_bindings(const struct vteprec_physical_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    ovs_assert(value_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_port_col_vlan_bindings);
}

/* Returns the vlan_stats column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * 'value_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes vlan_stats's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_port_get_vlan_stats(const struct vteprec_physical_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    ovs_assert(value_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_port_col_vlan_stats);
}

void
vteprec_physical_port_set_description(const struct vteprec_physical_port *row, const char *description)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, description);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_DESCRIPTION], &datum);
}

void
vteprec_physical_port_set_name(const struct vteprec_physical_port *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_NAME], &datum);
}

void
vteprec_physical_port_set_port_fault_status(const struct vteprec_physical_port *row, char **port_fault_status, size_t n_port_fault_status)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_port_fault_status;
    datum.keys = n_port_fault_status ? xmalloc(n_port_fault_status * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (i = 0; i < n_port_fault_status; i++) {
        datum.keys[i].string = xstrdup(port_fault_status[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_PORT_FAULT_STATUS], &datum);
}

void
vteprec_physical_port_set_vlan_bindings(const struct vteprec_physical_port *row, const int64_t *key_vlan_bindings, struct vteprec_logical_switch **value_vlan_bindings, size_t n_vlan_bindings)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_vlan_bindings;
    datum.keys = n_vlan_bindings ? xmalloc(n_vlan_bindings * sizeof *datum.keys) : NULL;
    datum.values = xmalloc(n_vlan_bindings * sizeof *datum.values);
    for (i = 0; i < n_vlan_bindings; i++) {
        datum.keys[i].integer = key_vlan_bindings[i];
        datum.values[i].uuid = value_vlan_bindings[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_UUID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_VLAN_BINDINGS], &datum);
}

void
vteprec_physical_port_set_vlan_stats(const struct vteprec_physical_port *row, const int64_t *key_vlan_stats, struct vteprec_logical_binding_stats **value_vlan_stats, size_t n_vlan_stats)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_vlan_stats;
    datum.keys = n_vlan_stats ? xmalloc(n_vlan_stats * sizeof *datum.keys) : NULL;
    datum.values = xmalloc(n_vlan_stats * sizeof *datum.values);
    for (i = 0; i < n_vlan_stats; i++) {
        datum.keys[i].integer = key_vlan_stats[i];
        datum.values[i].uuid = value_vlan_stats[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_UUID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_COL_VLAN_STATS], &datum);
}

struct ovsdb_idl_column vteprec_physical_port_columns[VTEPREC_PHYSICAL_PORT_N_COLUMNS];

static void
vteprec_physical_port_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_physical_port_col_description. */
    c = &vteprec_physical_port_col_description;
    c->name = "description";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_physical_port_parse_description;
    c->unparse = vteprec_physical_port_unparse_description;

    /* Initialize vteprec_physical_port_col_name. */
    c = &vteprec_physical_port_col_name;
    c->name = "name";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_physical_port_parse_name;
    c->unparse = vteprec_physical_port_unparse_name;

    /* Initialize vteprec_physical_port_col_port_fault_status. */
    c = &vteprec_physical_port_col_port_fault_status;
    c->name = "port_fault_status";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_physical_port_parse_port_fault_status;
    c->unparse = vteprec_physical_port_unparse_port_fault_status;

    /* Initialize vteprec_physical_port_col_vlan_bindings. */
    c = &vteprec_physical_port_col_vlan_bindings;
    c->name = "vlan_bindings";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    c->type.key.u.integer.max = INT64_C(4095);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_UUID);
    c->type.value.u.uuid.refTableName = "Logical_Switch";
    c->type.value.u.uuid.refType = OVSDB_REF_STRONG;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_physical_port_parse_vlan_bindings;
    c->unparse = vteprec_physical_port_unparse_vlan_bindings;

    /* Initialize vteprec_physical_port_col_vlan_stats. */
    c = &vteprec_physical_port_col_vlan_stats;
    c->name = "vlan_stats";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    c->type.key.u.integer.max = INT64_C(4095);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_UUID);
    c->type.value.u.uuid.refTableName = "Logical_Binding_Stats";
    c->type.value.u.uuid.refType = OVSDB_REF_STRONG;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_physical_port_parse_vlan_stats;
    c->unparse = vteprec_physical_port_unparse_vlan_stats;
}

/* Physical_Switch table. */

static void
vteprec_physical_switch_parse_description(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->description = datum->keys[0].string;
    } else {
        row->description = "";
    }
}

static void
vteprec_physical_switch_parse_management_ips(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->management_ips = NULL;
    row->n_management_ips = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_management_ips) {
            row->management_ips = xmalloc(datum->n * sizeof *row->management_ips);
        }
        row->management_ips[row->n_management_ips] = datum->keys[i].string;
        row->n_management_ips++;
    }
}

static void
vteprec_physical_switch_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
vteprec_physical_switch_parse_ports(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->ports = NULL;
    row->n_ports = 0;
    for (i = 0; i < datum->n; i++) {
        struct vteprec_physical_port *keyRow = vteprec_physical_port_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_PORT], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_ports) {
                row->ports = xmalloc(datum->n * sizeof *row->ports);
            }
            row->ports[row->n_ports] = keyRow;
            row->n_ports++;
        }
    }
}

static void
vteprec_physical_switch_parse_switch_fault_status(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->switch_fault_status = NULL;
    row->n_switch_fault_status = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_switch_fault_status) {
            row->switch_fault_status = xmalloc(datum->n * sizeof *row->switch_fault_status);
        }
        row->switch_fault_status[row->n_switch_fault_status] = datum->keys[i].string;
        row->n_switch_fault_status++;
    }
}

static void
vteprec_physical_switch_parse_tunnel_ips(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->tunnel_ips = NULL;
    row->n_tunnel_ips = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_tunnel_ips) {
            row->tunnel_ips = xmalloc(datum->n * sizeof *row->tunnel_ips);
        }
        row->tunnel_ips[row->n_tunnel_ips] = datum->keys[i].string;
        row->n_tunnel_ips++;
    }
}

static void
vteprec_physical_switch_parse_tunnels(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);
    size_t i;

    ovs_assert(inited);
    row->tunnels = NULL;
    row->n_tunnels = 0;
    for (i = 0; i < datum->n; i++) {
        struct vteprec_tunnel *keyRow = vteprec_tunnel_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_TUNNEL], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_tunnels) {
                row->tunnels = xmalloc(datum->n * sizeof *row->tunnels);
            }
            row->tunnels[row->n_tunnels] = keyRow;
            row->n_tunnels++;
        }
    }
}

static void
vteprec_physical_switch_unparse_description(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_physical_switch_unparse_management_ips(struct ovsdb_idl_row *row_)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);

    ovs_assert(inited);
    free(row->management_ips);
}

static void
vteprec_physical_switch_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_physical_switch_unparse_ports(struct ovsdb_idl_row *row_)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);

    ovs_assert(inited);
    free(row->ports);
}

static void
vteprec_physical_switch_unparse_switch_fault_status(struct ovsdb_idl_row *row_)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);

    ovs_assert(inited);
    free(row->switch_fault_status);
}

static void
vteprec_physical_switch_unparse_tunnel_ips(struct ovsdb_idl_row *row_)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);

    ovs_assert(inited);
    free(row->tunnel_ips);
}

static void
vteprec_physical_switch_unparse_tunnels(struct ovsdb_idl_row *row_)
{
    struct vteprec_physical_switch *row = vteprec_physical_switch_cast(row_);

    ovs_assert(inited);
    free(row->tunnels);
}

static void
vteprec_physical_switch_init__(struct ovsdb_idl_row *row)
{
    vteprec_physical_switch_init(vteprec_physical_switch_cast(row));
}

void
vteprec_physical_switch_init(struct vteprec_physical_switch *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_physical_switch *
vteprec_physical_switch_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_physical_switch_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_SWITCH], uuid));
}

const struct vteprec_physical_switch *
vteprec_physical_switch_first(const struct ovsdb_idl *idl)
{
    return vteprec_physical_switch_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_SWITCH]));
}

const struct vteprec_physical_switch *
vteprec_physical_switch_next(const struct vteprec_physical_switch *row)
{
    return vteprec_physical_switch_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_physical_switch_delete(const struct vteprec_physical_switch *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_physical_switch *
vteprec_physical_switch_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_physical_switch_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_SWITCH], NULL));
}


void
vteprec_physical_switch_verify_description(const struct vteprec_physical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_DESCRIPTION]);
}

void
vteprec_physical_switch_verify_management_ips(const struct vteprec_physical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_MANAGEMENT_IPS]);
}

void
vteprec_physical_switch_verify_name(const struct vteprec_physical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_NAME]);
}

void
vteprec_physical_switch_verify_ports(const struct vteprec_physical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_PORTS]);
}

void
vteprec_physical_switch_verify_switch_fault_status(const struct vteprec_physical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_SWITCH_FAULT_STATUS]);
}

void
vteprec_physical_switch_verify_tunnel_ips(const struct vteprec_physical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_TUNNEL_IPS]);
}

void
vteprec_physical_switch_verify_tunnels(const struct vteprec_physical_switch *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_TUNNELS]);
}

/* Returns the description column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes description's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_switch_get_description(const struct vteprec_physical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_switch_col_description);
}

/* Returns the management_ips column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes management_ips's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_switch_get_management_ips(const struct vteprec_physical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_switch_col_management_ips);
}

/* Returns the name column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_switch_get_name(const struct vteprec_physical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_switch_col_name);
}

/* Returns the ports column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes ports's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_switch_get_ports(const struct vteprec_physical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_switch_col_ports);
}

/* Returns the switch_fault_status column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes switch_fault_status's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_switch_get_switch_fault_status(const struct vteprec_physical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_switch_col_switch_fault_status);
}

/* Returns the tunnel_ips column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes tunnel_ips's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_switch_get_tunnel_ips(const struct vteprec_physical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_switch_col_tunnel_ips);
}

/* Returns the tunnels column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes tunnels's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_physical_switch_get_tunnels(const struct vteprec_physical_switch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_physical_switch_col_tunnels);
}

void
vteprec_physical_switch_set_description(const struct vteprec_physical_switch *row, const char *description)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, description);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_DESCRIPTION], &datum);
}

void
vteprec_physical_switch_set_management_ips(const struct vteprec_physical_switch *row, char **management_ips, size_t n_management_ips)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_management_ips;
    datum.keys = n_management_ips ? xmalloc(n_management_ips * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (i = 0; i < n_management_ips; i++) {
        datum.keys[i].string = xstrdup(management_ips[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_MANAGEMENT_IPS], &datum);
}

void
vteprec_physical_switch_set_name(const struct vteprec_physical_switch *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_NAME], &datum);
}

void
vteprec_physical_switch_set_ports(const struct vteprec_physical_switch *row, struct vteprec_physical_port **ports, size_t n_ports)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_ports;
    datum.keys = n_ports ? xmalloc(n_ports * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (i = 0; i < n_ports; i++) {
        datum.keys[i].uuid = ports[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_PORTS], &datum);
}

void
vteprec_physical_switch_set_switch_fault_status(const struct vteprec_physical_switch *row, char **switch_fault_status, size_t n_switch_fault_status)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_switch_fault_status;
    datum.keys = n_switch_fault_status ? xmalloc(n_switch_fault_status * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (i = 0; i < n_switch_fault_status; i++) {
        datum.keys[i].string = xstrdup(switch_fault_status[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_SWITCH_FAULT_STATUS], &datum);
}

void
vteprec_physical_switch_set_tunnel_ips(const struct vteprec_physical_switch *row, char **tunnel_ips, size_t n_tunnel_ips)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_tunnel_ips;
    datum.keys = n_tunnel_ips ? xmalloc(n_tunnel_ips * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (i = 0; i < n_tunnel_ips; i++) {
        datum.keys[i].string = xstrdup(tunnel_ips[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_TUNNEL_IPS], &datum);
}

void
vteprec_physical_switch_set_tunnels(const struct vteprec_physical_switch *row, struct vteprec_tunnel **tunnels, size_t n_tunnels)
{
    struct ovsdb_datum datum;
    size_t i;

    ovs_assert(inited);
    datum.n = n_tunnels;
    datum.keys = n_tunnels ? xmalloc(n_tunnels * sizeof *datum.keys) : NULL;
    datum.values = NULL;
    for (i = 0; i < n_tunnels; i++) {
        datum.keys[i].uuid = tunnels[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_COL_TUNNELS], &datum);
}

struct ovsdb_idl_column vteprec_physical_switch_columns[VTEPREC_PHYSICAL_SWITCH_N_COLUMNS];

static void
vteprec_physical_switch_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_physical_switch_col_description. */
    c = &vteprec_physical_switch_col_description;
    c->name = "description";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_physical_switch_parse_description;
    c->unparse = vteprec_physical_switch_unparse_description;

    /* Initialize vteprec_physical_switch_col_management_ips. */
    c = &vteprec_physical_switch_col_management_ips;
    c->name = "management_ips";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_physical_switch_parse_management_ips;
    c->unparse = vteprec_physical_switch_unparse_management_ips;

    /* Initialize vteprec_physical_switch_col_name. */
    c = &vteprec_physical_switch_col_name;
    c->name = "name";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_physical_switch_parse_name;
    c->unparse = vteprec_physical_switch_unparse_name;

    /* Initialize vteprec_physical_switch_col_ports. */
    c = &vteprec_physical_switch_col_ports;
    c->name = "ports";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Port";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_physical_switch_parse_ports;
    c->unparse = vteprec_physical_switch_unparse_ports;

    /* Initialize vteprec_physical_switch_col_switch_fault_status. */
    c = &vteprec_physical_switch_col_switch_fault_status;
    c->name = "switch_fault_status";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_physical_switch_parse_switch_fault_status;
    c->unparse = vteprec_physical_switch_unparse_switch_fault_status;

    /* Initialize vteprec_physical_switch_col_tunnel_ips. */
    c = &vteprec_physical_switch_col_tunnel_ips;
    c->name = "tunnel_ips";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_physical_switch_parse_tunnel_ips;
    c->unparse = vteprec_physical_switch_unparse_tunnel_ips;

    /* Initialize vteprec_physical_switch_col_tunnels. */
    c = &vteprec_physical_switch_col_tunnels;
    c->name = "tunnels";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Tunnel";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_physical_switch_parse_tunnels;
    c->unparse = vteprec_physical_switch_unparse_tunnels;
}

/* Tunnel table. */

static void
vteprec_tunnel_parse_bfd_config_local(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);
    size_t i;

    ovs_assert(inited);
    smap_init(&row->bfd_config_local);
    for (i = 0; i < datum->n; i++) {
        smap_add(&row->bfd_config_local,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
vteprec_tunnel_parse_bfd_config_remote(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);
    size_t i;

    ovs_assert(inited);
    smap_init(&row->bfd_config_remote);
    for (i = 0; i < datum->n; i++) {
        smap_add(&row->bfd_config_remote,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
vteprec_tunnel_parse_bfd_params(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);
    size_t i;

    ovs_assert(inited);
    smap_init(&row->bfd_params);
    for (i = 0; i < datum->n; i++) {
        smap_add(&row->bfd_params,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
vteprec_tunnel_parse_bfd_status(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);
    size_t i;

    ovs_assert(inited);
    smap_init(&row->bfd_status);
    for (i = 0; i < datum->n; i++) {
        smap_add(&row->bfd_status,
                 datum->keys[i].string,
                 datum->values[i].string);
    }
}

static void
vteprec_tunnel_parse_local(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->local = vteprec_physical_locator_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR], &datum->keys[0].uuid));
    } else {
        row->local = NULL;
    }
}

static void
vteprec_tunnel_parse_remote(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->remote = vteprec_physical_locator_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR], &datum->keys[0].uuid));
    } else {
        row->remote = NULL;
    }
}

static void
vteprec_tunnel_unparse_bfd_config_local(struct ovsdb_idl_row *row_)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);

    ovs_assert(inited);
    smap_destroy(&row->bfd_config_local);
}

static void
vteprec_tunnel_unparse_bfd_config_remote(struct ovsdb_idl_row *row_)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);

    ovs_assert(inited);
    smap_destroy(&row->bfd_config_remote);
}

static void
vteprec_tunnel_unparse_bfd_params(struct ovsdb_idl_row *row_)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);

    ovs_assert(inited);
    smap_destroy(&row->bfd_params);
}

static void
vteprec_tunnel_unparse_bfd_status(struct ovsdb_idl_row *row_)
{
    struct vteprec_tunnel *row = vteprec_tunnel_cast(row_);

    ovs_assert(inited);
    smap_destroy(&row->bfd_status);
}

static void
vteprec_tunnel_unparse_local(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_tunnel_unparse_remote(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_tunnel_init__(struct ovsdb_idl_row *row)
{
    vteprec_tunnel_init(vteprec_tunnel_cast(row));
}

void
vteprec_tunnel_init(struct vteprec_tunnel *row)
{
    memset(row, 0, sizeof *row); 
    smap_init(&row->bfd_config_local);
    smap_init(&row->bfd_config_remote);
    smap_init(&row->bfd_params);
    smap_init(&row->bfd_status);
}

const struct vteprec_tunnel *
vteprec_tunnel_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_tunnel_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_TUNNEL], uuid));
}

const struct vteprec_tunnel *
vteprec_tunnel_first(const struct ovsdb_idl *idl)
{
    return vteprec_tunnel_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_TUNNEL]));
}

const struct vteprec_tunnel *
vteprec_tunnel_next(const struct vteprec_tunnel *row)
{
    return vteprec_tunnel_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_tunnel_delete(const struct vteprec_tunnel *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_tunnel *
vteprec_tunnel_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_tunnel_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_TUNNEL], NULL));
}


void
vteprec_tunnel_verify_bfd_config_local(const struct vteprec_tunnel *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_BFD_CONFIG_LOCAL]);
}

void
vteprec_tunnel_verify_bfd_config_remote(const struct vteprec_tunnel *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_BFD_CONFIG_REMOTE]);
}

void
vteprec_tunnel_verify_bfd_params(const struct vteprec_tunnel *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_BFD_PARAMS]);
}

void
vteprec_tunnel_verify_bfd_status(const struct vteprec_tunnel *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_BFD_STATUS]);
}

void
vteprec_tunnel_verify_local(const struct vteprec_tunnel *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_LOCAL]);
}

void
vteprec_tunnel_verify_remote(const struct vteprec_tunnel *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_REMOTE]);
}

/* Returns the bfd_config_local column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes bfd_config_local's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_tunnel_get_bfd_config_local(const struct vteprec_tunnel *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_tunnel_col_bfd_config_local);
}

/* Returns the bfd_config_remote column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes bfd_config_remote's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_tunnel_get_bfd_config_remote(const struct vteprec_tunnel *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_tunnel_col_bfd_config_remote);
}

/* Returns the bfd_params column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes bfd_params's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_tunnel_get_bfd_params(const struct vteprec_tunnel *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_tunnel_col_bfd_params);
}

/* Returns the bfd_status column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes bfd_status's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_tunnel_get_bfd_status(const struct vteprec_tunnel *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    ovs_assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_tunnel_col_bfd_status);
}

/* Returns the local column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes local's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_tunnel_get_local(const struct vteprec_tunnel *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_tunnel_col_local);
}

/* Returns the remote column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes remote's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_tunnel_get_remote(const struct vteprec_tunnel *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_tunnel_col_remote);
}

void
vteprec_tunnel_set_bfd_config_local(const struct vteprec_tunnel *row, const struct smap *smap)
{
    struct ovsdb_datum datum;

    ovs_assert(inited);
    if (smap) {
        struct smap_node *node;
        size_t i;

        datum.n = smap_count(smap);
        datum.keys = xmalloc(datum.n * sizeof *datum.keys);
        datum.values = xmalloc(datum.n * sizeof *datum.values);

        i = 0;
        SMAP_FOR_EACH (node, smap) {
            datum.keys[i].string = xstrdup(node->key);
            datum.values[i].string = xstrdup(node->value);
            i++;
        }
        ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_BFD_CONFIG_LOCAL],
                        &datum);
}


void
vteprec_tunnel_set_bfd_config_remote(const struct vteprec_tunnel *row, const struct smap *smap)
{
    struct ovsdb_datum datum;

    ovs_assert(inited);
    if (smap) {
        struct smap_node *node;
        size_t i;

        datum.n = smap_count(smap);
        datum.keys = xmalloc(datum.n * sizeof *datum.keys);
        datum.values = xmalloc(datum.n * sizeof *datum.values);

        i = 0;
        SMAP_FOR_EACH (node, smap) {
            datum.keys[i].string = xstrdup(node->key);
            datum.values[i].string = xstrdup(node->value);
            i++;
        }
        ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_BFD_CONFIG_REMOTE],
                        &datum);
}


void
vteprec_tunnel_set_bfd_params(const struct vteprec_tunnel *row, const struct smap *smap)
{
    struct ovsdb_datum datum;

    ovs_assert(inited);
    if (smap) {
        struct smap_node *node;
        size_t i;

        datum.n = smap_count(smap);
        datum.keys = xmalloc(datum.n * sizeof *datum.keys);
        datum.values = xmalloc(datum.n * sizeof *datum.values);

        i = 0;
        SMAP_FOR_EACH (node, smap) {
            datum.keys[i].string = xstrdup(node->key);
            datum.values[i].string = xstrdup(node->value);
            i++;
        }
        ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_BFD_PARAMS],
                        &datum);
}


void
vteprec_tunnel_set_bfd_status(const struct vteprec_tunnel *row, const struct smap *smap)
{
    struct ovsdb_datum datum;

    ovs_assert(inited);
    if (smap) {
        struct smap_node *node;
        size_t i;

        datum.n = smap_count(smap);
        datum.keys = xmalloc(datum.n * sizeof *datum.keys);
        datum.values = xmalloc(datum.n * sizeof *datum.values);

        i = 0;
        SMAP_FOR_EACH (node, smap) {
            datum.keys[i].string = xstrdup(node->key);
            datum.values[i].string = xstrdup(node->value);
            i++;
        }
        ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    } else {
        ovsdb_datum_init_empty(&datum);
    }
    ovsdb_idl_txn_write(&row->header_,
                        &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_BFD_STATUS],
                        &datum);
}


void
vteprec_tunnel_set_local(const struct vteprec_tunnel *row, const struct vteprec_physical_locator *local)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = local->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_LOCAL], &datum);
}

void
vteprec_tunnel_set_remote(const struct vteprec_tunnel *row, const struct vteprec_physical_locator *remote)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = remote->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_tunnel_columns[VTEPREC_TUNNEL_COL_REMOTE], &datum);
}

struct ovsdb_idl_column vteprec_tunnel_columns[VTEPREC_TUNNEL_N_COLUMNS];

static void
vteprec_tunnel_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_tunnel_col_bfd_config_local. */
    c = &vteprec_tunnel_col_bfd_config_local;
    c->name = "bfd_config_local";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_tunnel_parse_bfd_config_local;
    c->unparse = vteprec_tunnel_unparse_bfd_config_local;

    /* Initialize vteprec_tunnel_col_bfd_config_remote. */
    c = &vteprec_tunnel_col_bfd_config_remote;
    c->name = "bfd_config_remote";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_tunnel_parse_bfd_config_remote;
    c->unparse = vteprec_tunnel_unparse_bfd_config_remote;

    /* Initialize vteprec_tunnel_col_bfd_params. */
    c = &vteprec_tunnel_col_bfd_params;
    c->name = "bfd_params";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_tunnel_parse_bfd_params;
    c->unparse = vteprec_tunnel_unparse_bfd_params;

    /* Initialize vteprec_tunnel_col_bfd_status. */
    c = &vteprec_tunnel_col_bfd_status;
    c->name = "bfd_status";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->mutable = true;
    c->parse = vteprec_tunnel_parse_bfd_status;
    c->unparse = vteprec_tunnel_unparse_bfd_status;

    /* Initialize vteprec_tunnel_col_local. */
    c = &vteprec_tunnel_col_local;
    c->name = "local";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Locator";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_tunnel_parse_local;
    c->unparse = vteprec_tunnel_unparse_local;

    /* Initialize vteprec_tunnel_col_remote. */
    c = &vteprec_tunnel_col_remote;
    c->name = "remote";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Locator";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_tunnel_parse_remote;
    c->unparse = vteprec_tunnel_unparse_remote;
}

/* Ucast_Macs_Local table. */

static void
vteprec_ucast_macs_local_parse_MAC(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_ucast_macs_local *row = vteprec_ucast_macs_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->MAC = datum->keys[0].string;
    } else {
        row->MAC = "";
    }
}

static void
vteprec_ucast_macs_local_parse_ipaddr(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_ucast_macs_local *row = vteprec_ucast_macs_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->ipaddr = datum->keys[0].string;
    } else {
        row->ipaddr = "";
    }
}

static void
vteprec_ucast_macs_local_parse_locator(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_ucast_macs_local *row = vteprec_ucast_macs_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->locator = vteprec_physical_locator_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR], &datum->keys[0].uuid));
    } else {
        row->locator = NULL;
    }
}

static void
vteprec_ucast_macs_local_parse_logical_switch(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_ucast_macs_local *row = vteprec_ucast_macs_local_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->logical_switch = vteprec_logical_switch_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_SWITCH], &datum->keys[0].uuid));
    } else {
        row->logical_switch = NULL;
    }
}

static void
vteprec_ucast_macs_local_unparse_MAC(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_ucast_macs_local_unparse_ipaddr(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_ucast_macs_local_unparse_locator(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_ucast_macs_local_unparse_logical_switch(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_ucast_macs_local_init__(struct ovsdb_idl_row *row)
{
    vteprec_ucast_macs_local_init(vteprec_ucast_macs_local_cast(row));
}

void
vteprec_ucast_macs_local_init(struct vteprec_ucast_macs_local *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_ucast_macs_local *
vteprec_ucast_macs_local_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_ucast_macs_local_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_UCAST_MACS_LOCAL], uuid));
}

const struct vteprec_ucast_macs_local *
vteprec_ucast_macs_local_first(const struct ovsdb_idl *idl)
{
    return vteprec_ucast_macs_local_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_UCAST_MACS_LOCAL]));
}

const struct vteprec_ucast_macs_local *
vteprec_ucast_macs_local_next(const struct vteprec_ucast_macs_local *row)
{
    return vteprec_ucast_macs_local_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_ucast_macs_local_delete(const struct vteprec_ucast_macs_local *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_ucast_macs_local *
vteprec_ucast_macs_local_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_ucast_macs_local_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_UCAST_MACS_LOCAL], NULL));
}


void
vteprec_ucast_macs_local_verify_MAC(const struct vteprec_ucast_macs_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_ucast_macs_local_columns[VTEPREC_UCAST_MACS_LOCAL_COL_MAC]);
}

void
vteprec_ucast_macs_local_verify_ipaddr(const struct vteprec_ucast_macs_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_ucast_macs_local_columns[VTEPREC_UCAST_MACS_LOCAL_COL_IPADDR]);
}

void
vteprec_ucast_macs_local_verify_locator(const struct vteprec_ucast_macs_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_ucast_macs_local_columns[VTEPREC_UCAST_MACS_LOCAL_COL_LOCATOR]);
}

void
vteprec_ucast_macs_local_verify_logical_switch(const struct vteprec_ucast_macs_local *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_ucast_macs_local_columns[VTEPREC_UCAST_MACS_LOCAL_COL_LOGICAL_SWITCH]);
}

/* Returns the MAC column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes MAC's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_ucast_macs_local_get_MAC(const struct vteprec_ucast_macs_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_ucast_macs_local_col_MAC);
}

/* Returns the ipaddr column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes ipaddr's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_ucast_macs_local_get_ipaddr(const struct vteprec_ucast_macs_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_ucast_macs_local_col_ipaddr);
}

/* Returns the locator column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes locator's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_ucast_macs_local_get_locator(const struct vteprec_ucast_macs_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_ucast_macs_local_col_locator);
}

/* Returns the logical_switch column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes logical_switch's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_ucast_macs_local_get_logical_switch(const struct vteprec_ucast_macs_local *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_ucast_macs_local_col_logical_switch);
}

void
vteprec_ucast_macs_local_set_MAC(const struct vteprec_ucast_macs_local *row, const char *MAC)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, MAC);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_ucast_macs_local_columns[VTEPREC_UCAST_MACS_LOCAL_COL_MAC], &datum);
}

void
vteprec_ucast_macs_local_set_ipaddr(const struct vteprec_ucast_macs_local *row, const char *ipaddr)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ipaddr);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_ucast_macs_local_columns[VTEPREC_UCAST_MACS_LOCAL_COL_IPADDR], &datum);
}

void
vteprec_ucast_macs_local_set_locator(const struct vteprec_ucast_macs_local *row, const struct vteprec_physical_locator *locator)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = locator->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_ucast_macs_local_columns[VTEPREC_UCAST_MACS_LOCAL_COL_LOCATOR], &datum);
}

void
vteprec_ucast_macs_local_set_logical_switch(const struct vteprec_ucast_macs_local *row, const struct vteprec_logical_switch *logical_switch)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = logical_switch->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_ucast_macs_local_columns[VTEPREC_UCAST_MACS_LOCAL_COL_LOGICAL_SWITCH], &datum);
}

struct ovsdb_idl_column vteprec_ucast_macs_local_columns[VTEPREC_UCAST_MACS_LOCAL_N_COLUMNS];

static void
vteprec_ucast_macs_local_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_ucast_macs_local_col_MAC. */
    c = &vteprec_ucast_macs_local_col_MAC;
    c->name = "MAC";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_ucast_macs_local_parse_MAC;
    c->unparse = vteprec_ucast_macs_local_unparse_MAC;

    /* Initialize vteprec_ucast_macs_local_col_ipaddr. */
    c = &vteprec_ucast_macs_local_col_ipaddr;
    c->name = "ipaddr";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_ucast_macs_local_parse_ipaddr;
    c->unparse = vteprec_ucast_macs_local_unparse_ipaddr;

    /* Initialize vteprec_ucast_macs_local_col_locator. */
    c = &vteprec_ucast_macs_local_col_locator;
    c->name = "locator";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Locator";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_ucast_macs_local_parse_locator;
    c->unparse = vteprec_ucast_macs_local_unparse_locator;

    /* Initialize vteprec_ucast_macs_local_col_logical_switch. */
    c = &vteprec_ucast_macs_local_col_logical_switch;
    c->name = "logical_switch";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Logical_Switch";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_ucast_macs_local_parse_logical_switch;
    c->unparse = vteprec_ucast_macs_local_unparse_logical_switch;
}

/* Ucast_Macs_Remote table. */

static void
vteprec_ucast_macs_remote_parse_MAC(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_ucast_macs_remote *row = vteprec_ucast_macs_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->MAC = datum->keys[0].string;
    } else {
        row->MAC = "";
    }
}

static void
vteprec_ucast_macs_remote_parse_ipaddr(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_ucast_macs_remote *row = vteprec_ucast_macs_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->ipaddr = datum->keys[0].string;
    } else {
        row->ipaddr = "";
    }
}

static void
vteprec_ucast_macs_remote_parse_locator(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_ucast_macs_remote *row = vteprec_ucast_macs_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->locator = vteprec_physical_locator_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_PHYSICAL_LOCATOR], &datum->keys[0].uuid));
    } else {
        row->locator = NULL;
    }
}

static void
vteprec_ucast_macs_remote_parse_logical_switch(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct vteprec_ucast_macs_remote *row = vteprec_ucast_macs_remote_cast(row_);

    ovs_assert(inited);
    if (datum->n >= 1) {
        row->logical_switch = vteprec_logical_switch_cast(ovsdb_idl_get_row_arc(row_, &vteprec_table_classes[VTEPREC_TABLE_LOGICAL_SWITCH], &datum->keys[0].uuid));
    } else {
        row->logical_switch = NULL;
    }
}

static void
vteprec_ucast_macs_remote_unparse_MAC(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_ucast_macs_remote_unparse_ipaddr(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_ucast_macs_remote_unparse_locator(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_ucast_macs_remote_unparse_logical_switch(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
vteprec_ucast_macs_remote_init__(struct ovsdb_idl_row *row)
{
    vteprec_ucast_macs_remote_init(vteprec_ucast_macs_remote_cast(row));
}

void
vteprec_ucast_macs_remote_init(struct vteprec_ucast_macs_remote *row)
{
    memset(row, 0, sizeof *row); 
}

const struct vteprec_ucast_macs_remote *
vteprec_ucast_macs_remote_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return vteprec_ucast_macs_remote_cast(ovsdb_idl_get_row_for_uuid(idl, &vteprec_table_classes[VTEPREC_TABLE_UCAST_MACS_REMOTE], uuid));
}

const struct vteprec_ucast_macs_remote *
vteprec_ucast_macs_remote_first(const struct ovsdb_idl *idl)
{
    return vteprec_ucast_macs_remote_cast(ovsdb_idl_first_row(idl, &vteprec_table_classes[VTEPREC_TABLE_UCAST_MACS_REMOTE]));
}

const struct vteprec_ucast_macs_remote *
vteprec_ucast_macs_remote_next(const struct vteprec_ucast_macs_remote *row)
{
    return vteprec_ucast_macs_remote_cast(ovsdb_idl_next_row(&row->header_));
}

void
vteprec_ucast_macs_remote_delete(const struct vteprec_ucast_macs_remote *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct vteprec_ucast_macs_remote *
vteprec_ucast_macs_remote_insert(struct ovsdb_idl_txn *txn)
{
    return vteprec_ucast_macs_remote_cast(ovsdb_idl_txn_insert(txn, &vteprec_table_classes[VTEPREC_TABLE_UCAST_MACS_REMOTE], NULL));
}


void
vteprec_ucast_macs_remote_verify_MAC(const struct vteprec_ucast_macs_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_ucast_macs_remote_columns[VTEPREC_UCAST_MACS_REMOTE_COL_MAC]);
}

void
vteprec_ucast_macs_remote_verify_ipaddr(const struct vteprec_ucast_macs_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_ucast_macs_remote_columns[VTEPREC_UCAST_MACS_REMOTE_COL_IPADDR]);
}

void
vteprec_ucast_macs_remote_verify_locator(const struct vteprec_ucast_macs_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_ucast_macs_remote_columns[VTEPREC_UCAST_MACS_REMOTE_COL_LOCATOR]);
}

void
vteprec_ucast_macs_remote_verify_logical_switch(const struct vteprec_ucast_macs_remote *row)
{
    ovs_assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &vteprec_ucast_macs_remote_columns[VTEPREC_UCAST_MACS_REMOTE_COL_LOGICAL_SWITCH]);
}

/* Returns the MAC column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes MAC's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_ucast_macs_remote_get_MAC(const struct vteprec_ucast_macs_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_ucast_macs_remote_col_MAC);
}

/* Returns the ipaddr column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes ipaddr's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_ucast_macs_remote_get_ipaddr(const struct vteprec_ucast_macs_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &vteprec_ucast_macs_remote_col_ipaddr);
}

/* Returns the locator column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes locator's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_ucast_macs_remote_get_locator(const struct vteprec_ucast_macs_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_ucast_macs_remote_col_locator);
}

/* Returns the logical_switch column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes logical_switch's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
vteprec_ucast_macs_remote_get_logical_switch(const struct vteprec_ucast_macs_remote *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &vteprec_ucast_macs_remote_col_logical_switch);
}

void
vteprec_ucast_macs_remote_set_MAC(const struct vteprec_ucast_macs_remote *row, const char *MAC)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, MAC);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_ucast_macs_remote_columns[VTEPREC_UCAST_MACS_REMOTE_COL_MAC], &datum);
}

void
vteprec_ucast_macs_remote_set_ipaddr(const struct vteprec_ucast_macs_remote *row, const char *ipaddr)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, ipaddr);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_ucast_macs_remote_columns[VTEPREC_UCAST_MACS_REMOTE_COL_IPADDR], &datum);
}

void
vteprec_ucast_macs_remote_set_locator(const struct vteprec_ucast_macs_remote *row, const struct vteprec_physical_locator *locator)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = locator->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_ucast_macs_remote_columns[VTEPREC_UCAST_MACS_REMOTE_COL_LOCATOR], &datum);
}

void
vteprec_ucast_macs_remote_set_logical_switch(const struct vteprec_ucast_macs_remote *row, const struct vteprec_logical_switch *logical_switch)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    ovs_assert(inited);
    datum.n = 1;
    datum.keys = &key;
    key.uuid = logical_switch->header_.uuid;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &vteprec_ucast_macs_remote_columns[VTEPREC_UCAST_MACS_REMOTE_COL_LOGICAL_SWITCH], &datum);
}

struct ovsdb_idl_column vteprec_ucast_macs_remote_columns[VTEPREC_UCAST_MACS_REMOTE_N_COLUMNS];

static void
vteprec_ucast_macs_remote_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize vteprec_ucast_macs_remote_col_MAC. */
    c = &vteprec_ucast_macs_remote_col_MAC;
    c->name = "MAC";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_ucast_macs_remote_parse_MAC;
    c->unparse = vteprec_ucast_macs_remote_unparse_MAC;

    /* Initialize vteprec_ucast_macs_remote_col_ipaddr. */
    c = &vteprec_ucast_macs_remote_col_ipaddr;
    c->name = "ipaddr";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_ucast_macs_remote_parse_ipaddr;
    c->unparse = vteprec_ucast_macs_remote_unparse_ipaddr;

    /* Initialize vteprec_ucast_macs_remote_col_locator. */
    c = &vteprec_ucast_macs_remote_col_locator;
    c->name = "locator";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Physical_Locator";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_ucast_macs_remote_parse_locator;
    c->unparse = vteprec_ucast_macs_remote_unparse_locator;

    /* Initialize vteprec_ucast_macs_remote_col_logical_switch. */
    c = &vteprec_ucast_macs_remote_col_logical_switch;
    c->name = "logical_switch";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Logical_Switch";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->mutable = true;
    c->parse = vteprec_ucast_macs_remote_parse_logical_switch;
    c->unparse = vteprec_ucast_macs_remote_unparse_logical_switch;
}

struct ovsdb_idl_table_class vteprec_table_classes[VTEPREC_N_TABLES] = {
    {"Arp_Sources_Local", true,
     vteprec_arp_sources_local_columns, ARRAY_SIZE(vteprec_arp_sources_local_columns),
     sizeof(struct vteprec_arp_sources_local), vteprec_arp_sources_local_init__},
    {"Arp_Sources_Remote", true,
     vteprec_arp_sources_remote_columns, ARRAY_SIZE(vteprec_arp_sources_remote_columns),
     sizeof(struct vteprec_arp_sources_remote), vteprec_arp_sources_remote_init__},
    {"Global", true,
     vteprec_global_columns, ARRAY_SIZE(vteprec_global_columns),
     sizeof(struct vteprec_global), vteprec_global_init__},
    {"Logical_Binding_Stats", false,
     vteprec_logical_binding_stats_columns, ARRAY_SIZE(vteprec_logical_binding_stats_columns),
     sizeof(struct vteprec_logical_binding_stats), vteprec_logical_binding_stats_init__},
    {"Logical_Router", true,
     vteprec_logical_router_columns, ARRAY_SIZE(vteprec_logical_router_columns),
     sizeof(struct vteprec_logical_router), vteprec_logical_router_init__},
    {"Logical_Switch", true,
     vteprec_logical_switch_columns, ARRAY_SIZE(vteprec_logical_switch_columns),
     sizeof(struct vteprec_logical_switch), vteprec_logical_switch_init__},
    {"Manager", false,
     vteprec_manager_columns, ARRAY_SIZE(vteprec_manager_columns),
     sizeof(struct vteprec_manager), vteprec_manager_init__},
    {"Mcast_Macs_Local", true,
     vteprec_mcast_macs_local_columns, ARRAY_SIZE(vteprec_mcast_macs_local_columns),
     sizeof(struct vteprec_mcast_macs_local), vteprec_mcast_macs_local_init__},
    {"Mcast_Macs_Remote", true,
     vteprec_mcast_macs_remote_columns, ARRAY_SIZE(vteprec_mcast_macs_remote_columns),
     sizeof(struct vteprec_mcast_macs_remote), vteprec_mcast_macs_remote_init__},
    {"Physical_Locator", false,
     vteprec_physical_locator_columns, ARRAY_SIZE(vteprec_physical_locator_columns),
     sizeof(struct vteprec_physical_locator), vteprec_physical_locator_init__},
    {"Physical_Locator_Set", false,
     vteprec_physical_locator_set_columns, ARRAY_SIZE(vteprec_physical_locator_set_columns),
     sizeof(struct vteprec_physical_locator_set), vteprec_physical_locator_set_init__},
    {"Physical_Port", false,
     vteprec_physical_port_columns, ARRAY_SIZE(vteprec_physical_port_columns),
     sizeof(struct vteprec_physical_port), vteprec_physical_port_init__},
    {"Physical_Switch", false,
     vteprec_physical_switch_columns, ARRAY_SIZE(vteprec_physical_switch_columns),
     sizeof(struct vteprec_physical_switch), vteprec_physical_switch_init__},
    {"Tunnel", false,
     vteprec_tunnel_columns, ARRAY_SIZE(vteprec_tunnel_columns),
     sizeof(struct vteprec_tunnel), vteprec_tunnel_init__},
    {"Ucast_Macs_Local", true,
     vteprec_ucast_macs_local_columns, ARRAY_SIZE(vteprec_ucast_macs_local_columns),
     sizeof(struct vteprec_ucast_macs_local), vteprec_ucast_macs_local_init__},
    {"Ucast_Macs_Remote", true,
     vteprec_ucast_macs_remote_columns, ARRAY_SIZE(vteprec_ucast_macs_remote_columns),
     sizeof(struct vteprec_ucast_macs_remote), vteprec_ucast_macs_remote_init__},
};

struct ovsdb_idl_class vteprec_idl_class = {
    "hardware_vtep", vteprec_table_classes, ARRAY_SIZE(vteprec_table_classes)
};

void
vteprec_init(void)
{
    if (inited) {
        return;
    }
    assert_single_threaded();
    inited = true;

    vteprec_arp_sources_local_columns_init();
    vteprec_arp_sources_remote_columns_init();
    vteprec_global_columns_init();
    vteprec_logical_binding_stats_columns_init();
    vteprec_logical_router_columns_init();
    vteprec_logical_switch_columns_init();
    vteprec_manager_columns_init();
    vteprec_mcast_macs_local_columns_init();
    vteprec_mcast_macs_remote_columns_init();
    vteprec_physical_locator_columns_init();
    vteprec_physical_locator_set_columns_init();
    vteprec_physical_port_columns_init();
    vteprec_physical_switch_columns_init();
    vteprec_tunnel_columns_init();
    vteprec_ucast_macs_local_columns_init();
    vteprec_ucast_macs_remote_columns_init();
}

/* Return the schema version.  The caller must not free the returned value. */
const char *
vteprec_get_db_version(void)
{
    return "1.3.0";
}

