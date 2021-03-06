#pragma once

#include <stdint.h>

#include "z80.h"

typedef uint8_t(*z80_op)(Z80*);

uint8_t z80_op_nop(Z80 *z);

static z80_op z80_op_table[] = {
/* Generated from z80_gen */
[0x0000] = z80_op_nop,
[0x0001] = z80_op_nop,
[0x0002] = z80_op_nop,
[0x0003] = z80_op_nop,
[0x0004] = z80_op_nop,
[0x0005] = z80_op_nop,
[0x0006] = z80_op_nop,
[0x0007] = z80_op_nop,
[0x0008] = z80_op_nop,
[0x0009] = z80_op_nop,
[0x000a] = z80_op_nop,
[0x000b] = z80_op_nop,
[0x000c] = z80_op_nop,
[0x000d] = z80_op_nop,
[0x000e] = z80_op_nop,
[0x000f] = z80_op_nop,
[0x0010] = z80_op_nop,
[0x0011] = z80_op_nop,
[0x0012] = z80_op_nop,
[0x0013] = z80_op_nop,
[0x0014] = z80_op_nop,
[0x0015] = z80_op_nop,
[0x0016] = z80_op_nop,
[0x0017] = z80_op_nop,
[0x0018] = z80_op_nop,
[0x0019] = z80_op_nop,
[0x001a] = z80_op_nop,
[0x001b] = z80_op_nop,
[0x001c] = z80_op_nop,
[0x001d] = z80_op_nop,
[0x001e] = z80_op_nop,
[0x001f] = z80_op_nop,
[0x0020] = z80_op_nop,
[0x0021] = z80_op_nop,
[0x0022] = z80_op_nop,
[0x0023] = z80_op_nop,
[0x0024] = z80_op_nop,
[0x0025] = z80_op_nop,
[0x0026] = z80_op_nop,
[0x0027] = z80_op_nop,
[0x0028] = z80_op_nop,
[0x0029] = z80_op_nop,
[0x002a] = z80_op_nop,
[0x002b] = z80_op_nop,
[0x002c] = z80_op_nop,
[0x002d] = z80_op_nop,
[0x002e] = z80_op_nop,
[0x002f] = z80_op_nop,
[0x0030] = z80_op_nop,
[0x0031] = z80_op_nop,
[0x0032] = z80_op_nop,
[0x0033] = z80_op_nop,
[0x0034] = z80_op_nop,
[0x0035] = z80_op_nop,
[0x0036] = z80_op_nop,
[0x0037] = z80_op_nop,
[0x0038] = z80_op_nop,
[0x0039] = z80_op_nop,
[0x003a] = z80_op_nop,
[0x003b] = z80_op_nop,
[0x003c] = z80_op_nop,
[0x003d] = z80_op_nop,
[0x003e] = z80_op_nop,
[0x003f] = z80_op_nop,
[0x0040] = z80_op_nop,
[0x0041] = z80_op_nop,
[0x0042] = z80_op_nop,
[0x0043] = z80_op_nop,
[0x0044] = z80_op_nop,
[0x0045] = z80_op_nop,
[0x0046] = z80_op_nop,
[0x0047] = z80_op_nop,
[0x0048] = z80_op_nop,
[0x0049] = z80_op_nop,
[0x004a] = z80_op_nop,
[0x004b] = z80_op_nop,
[0x004c] = z80_op_nop,
[0x004d] = z80_op_nop,
[0x004e] = z80_op_nop,
[0x004f] = z80_op_nop,
[0x0050] = z80_op_nop,
[0x0051] = z80_op_nop,
[0x0052] = z80_op_nop,
[0x0053] = z80_op_nop,
[0x0054] = z80_op_nop,
[0x0055] = z80_op_nop,
[0x0056] = z80_op_nop,
[0x0057] = z80_op_nop,
[0x0058] = z80_op_nop,
[0x0059] = z80_op_nop,
[0x005a] = z80_op_nop,
[0x005b] = z80_op_nop,
[0x005c] = z80_op_nop,
[0x005d] = z80_op_nop,
[0x005e] = z80_op_nop,
[0x005f] = z80_op_nop,
[0x0060] = z80_op_nop,
[0x0061] = z80_op_nop,
[0x0062] = z80_op_nop,
[0x0063] = z80_op_nop,
[0x0064] = z80_op_nop,
[0x0065] = z80_op_nop,
[0x0066] = z80_op_nop,
[0x0067] = z80_op_nop,
[0x0068] = z80_op_nop,
[0x0069] = z80_op_nop,
[0x006a] = z80_op_nop,
[0x006b] = z80_op_nop,
[0x006c] = z80_op_nop,
[0x006d] = z80_op_nop,
[0x006e] = z80_op_nop,
[0x006f] = z80_op_nop,
[0x0070] = z80_op_nop,
[0x0071] = z80_op_nop,
[0x0072] = z80_op_nop,
[0x0073] = z80_op_nop,
[0x0074] = z80_op_nop,
[0x0075] = z80_op_nop,
[0x0076] = z80_op_nop,
[0x0077] = z80_op_nop,
[0x0078] = z80_op_nop,
[0x0079] = z80_op_nop,
[0x007a] = z80_op_nop,
[0x007b] = z80_op_nop,
[0x007c] = z80_op_nop,
[0x007d] = z80_op_nop,
[0x007e] = z80_op_nop,
[0x007f] = z80_op_nop,
[0x0080] = z80_op_nop,
[0x0081] = z80_op_nop,
[0x0082] = z80_op_nop,
[0x0083] = z80_op_nop,
[0x0084] = z80_op_nop,
[0x0085] = z80_op_nop,
[0x0086] = z80_op_nop,
[0x0087] = z80_op_nop,
[0x0088] = z80_op_nop,
[0x0089] = z80_op_nop,
[0x008a] = z80_op_nop,
[0x008b] = z80_op_nop,
[0x008c] = z80_op_nop,
[0x008d] = z80_op_nop,
[0x008e] = z80_op_nop,
[0x008f] = z80_op_nop,
[0x0090] = z80_op_nop,
[0x0091] = z80_op_nop,
[0x0092] = z80_op_nop,
[0x0093] = z80_op_nop,
[0x0094] = z80_op_nop,
[0x0095] = z80_op_nop,
[0x0096] = z80_op_nop,
[0x0097] = z80_op_nop,
[0x0098] = z80_op_nop,
[0x0099] = z80_op_nop,
[0x009a] = z80_op_nop,
[0x009b] = z80_op_nop,
[0x009c] = z80_op_nop,
[0x009d] = z80_op_nop,
[0x009e] = z80_op_nop,
[0x009f] = z80_op_nop,
[0x00a0] = z80_op_nop,
[0x00a1] = z80_op_nop,
[0x00a2] = z80_op_nop,
[0x00a3] = z80_op_nop,
[0x00a4] = z80_op_nop,
[0x00a5] = z80_op_nop,
[0x00a6] = z80_op_nop,
[0x00a7] = z80_op_nop,
[0x00a8] = z80_op_nop,
[0x00a9] = z80_op_nop,
[0x00aa] = z80_op_nop,
[0x00ab] = z80_op_nop,
[0x00ac] = z80_op_nop,
[0x00ad] = z80_op_nop,
[0x00ae] = z80_op_nop,
[0x00af] = z80_op_nop,
[0x00b0] = z80_op_nop,
[0x00b1] = z80_op_nop,
[0x00b2] = z80_op_nop,
[0x00b3] = z80_op_nop,
[0x00b4] = z80_op_nop,
[0x00b5] = z80_op_nop,
[0x00b6] = z80_op_nop,
[0x00b7] = z80_op_nop,
[0x00b8] = z80_op_nop,
[0x00b9] = z80_op_nop,
[0x00ba] = z80_op_nop,
[0x00bb] = z80_op_nop,
[0x00bc] = z80_op_nop,
[0x00bd] = z80_op_nop,
[0x00be] = z80_op_nop,
[0x00bf] = z80_op_nop,
[0x00c0] = z80_op_nop,
[0x00c1] = z80_op_nop,
[0x00c2] = z80_op_nop,
[0x00c3] = z80_op_nop,
[0x00c4] = z80_op_nop,
[0x00c5] = z80_op_nop,
[0x00c6] = z80_op_nop,
[0x00c7] = z80_op_nop,
[0x00c8] = z80_op_nop,
[0x00c9] = z80_op_nop,
[0x00ca] = z80_op_nop,
[0xcb00] = z80_op_nop,
[0xcb01] = z80_op_nop,
[0xcb02] = z80_op_nop,
[0xcb03] = z80_op_nop,
[0xcb04] = z80_op_nop,
[0xcb05] = z80_op_nop,
[0xcb06] = z80_op_nop,
[0xcb07] = z80_op_nop,
[0xcb08] = z80_op_nop,
[0xcb09] = z80_op_nop,
[0xcb0a] = z80_op_nop,
[0xcb0b] = z80_op_nop,
[0xcb0c] = z80_op_nop,
[0xcb0d] = z80_op_nop,
[0xcb0e] = z80_op_nop,
[0xcb0f] = z80_op_nop,
[0xcb10] = z80_op_nop,
[0xcb11] = z80_op_nop,
[0xcb12] = z80_op_nop,
[0xcb13] = z80_op_nop,
[0xcb14] = z80_op_nop,
[0xcb15] = z80_op_nop,
[0xcb16] = z80_op_nop,
[0xcb17] = z80_op_nop,
[0xcb18] = z80_op_nop,
[0xcb19] = z80_op_nop,
[0xcb1a] = z80_op_nop,
[0xcb1b] = z80_op_nop,
[0xcb1c] = z80_op_nop,
[0xcb1d] = z80_op_nop,
[0xcb1e] = z80_op_nop,
[0xcb1f] = z80_op_nop,
[0xcb20] = z80_op_nop,
[0xcb21] = z80_op_nop,
[0xcb22] = z80_op_nop,
[0xcb23] = z80_op_nop,
[0xcb24] = z80_op_nop,
[0xcb25] = z80_op_nop,
[0xcb26] = z80_op_nop,
[0xcb27] = z80_op_nop,
[0xcb28] = z80_op_nop,
[0xcb29] = z80_op_nop,
[0xcb2a] = z80_op_nop,
[0xcb2b] = z80_op_nop,
[0xcb2c] = z80_op_nop,
[0xcb2d] = z80_op_nop,
[0xcb2e] = z80_op_nop,
[0xcb2f] = z80_op_nop,
[0xcb38] = z80_op_nop,
[0xcb39] = z80_op_nop,
[0xcb3a] = z80_op_nop,
[0xcb3b] = z80_op_nop,
[0xcb3c] = z80_op_nop,
[0xcb3d] = z80_op_nop,
[0xcb3e] = z80_op_nop,
[0xcb3f] = z80_op_nop,
[0xcb40] = z80_op_nop,
[0xcb41] = z80_op_nop,
[0xcb42] = z80_op_nop,
[0xcb43] = z80_op_nop,
[0xcb44] = z80_op_nop,
[0xcb45] = z80_op_nop,
[0xcb46] = z80_op_nop,
[0xcb47] = z80_op_nop,
[0xcb48] = z80_op_nop,
[0xcb49] = z80_op_nop,
[0xcb4a] = z80_op_nop,
[0xcb4b] = z80_op_nop,
[0xcb4c] = z80_op_nop,
[0xcb4d] = z80_op_nop,
[0xcb4e] = z80_op_nop,
[0xcb4f] = z80_op_nop,
[0xcb50] = z80_op_nop,
[0xcb51] = z80_op_nop,
[0xcb52] = z80_op_nop,
[0xcb53] = z80_op_nop,
[0xcb54] = z80_op_nop,
[0xcb55] = z80_op_nop,
[0xcb56] = z80_op_nop,
[0xcb57] = z80_op_nop,
[0xcb58] = z80_op_nop,
[0xcb59] = z80_op_nop,
[0xcb5a] = z80_op_nop,
[0xcb5b] = z80_op_nop,
[0xcb5c] = z80_op_nop,
[0xcb5d] = z80_op_nop,
[0xcb5e] = z80_op_nop,
[0xcb5f] = z80_op_nop,
[0xcb60] = z80_op_nop,
[0xcb61] = z80_op_nop,
[0xcb62] = z80_op_nop,
[0xcb63] = z80_op_nop,
[0xcb64] = z80_op_nop,
[0xcb65] = z80_op_nop,
[0xcb66] = z80_op_nop,
[0xcb67] = z80_op_nop,
[0xcb68] = z80_op_nop,
[0xcb69] = z80_op_nop,
[0xcb6a] = z80_op_nop,
[0xcb6b] = z80_op_nop,
[0xcb6c] = z80_op_nop,
[0xcb6d] = z80_op_nop,
[0xcb6e] = z80_op_nop,
[0xcb6f] = z80_op_nop,
[0xcb70] = z80_op_nop,
[0xcb71] = z80_op_nop,
[0xcb72] = z80_op_nop,
[0xcb73] = z80_op_nop,
[0xcb74] = z80_op_nop,
[0xcb75] = z80_op_nop,
[0xcb76] = z80_op_nop,
[0xcb77] = z80_op_nop,
[0xcb78] = z80_op_nop,
[0xcb79] = z80_op_nop,
[0xcb7a] = z80_op_nop,
[0xcb7b] = z80_op_nop,
[0xcb7c] = z80_op_nop,
[0xcb7d] = z80_op_nop,
[0xcb7e] = z80_op_nop,
[0xcb7f] = z80_op_nop,
[0xcb80] = z80_op_nop,
[0xcb81] = z80_op_nop,
[0xcb82] = z80_op_nop,
[0xcb83] = z80_op_nop,
[0xcb84] = z80_op_nop,
[0xcb85] = z80_op_nop,
[0xcb86] = z80_op_nop,
[0xcb87] = z80_op_nop,
[0xcb88] = z80_op_nop,
[0xcb89] = z80_op_nop,
[0xcb8a] = z80_op_nop,
[0xcb8b] = z80_op_nop,
[0xcb8c] = z80_op_nop,
[0xcb8d] = z80_op_nop,
[0xcb8e] = z80_op_nop,
[0xcb8f] = z80_op_nop,
[0xcb90] = z80_op_nop,
[0xcb91] = z80_op_nop,
[0xcb92] = z80_op_nop,
[0xcb93] = z80_op_nop,
[0xcb94] = z80_op_nop,
[0xcb95] = z80_op_nop,
[0xcb96] = z80_op_nop,
[0xcb97] = z80_op_nop,
[0xcb98] = z80_op_nop,
[0xcb99] = z80_op_nop,
[0xcb9a] = z80_op_nop,
[0xcb9b] = z80_op_nop,
[0xcb9c] = z80_op_nop,
[0xcb9d] = z80_op_nop,
[0xcb9e] = z80_op_nop,
[0xcb9f] = z80_op_nop,
[0xcba0] = z80_op_nop,
[0xcba1] = z80_op_nop,
[0xcba2] = z80_op_nop,
[0xcba3] = z80_op_nop,
[0xcba4] = z80_op_nop,
[0xcba5] = z80_op_nop,
[0xcba6] = z80_op_nop,
[0xcba7] = z80_op_nop,
[0xcba8] = z80_op_nop,
[0xcba9] = z80_op_nop,
[0xcbaa] = z80_op_nop,
[0xcbab] = z80_op_nop,
[0xcbac] = z80_op_nop,
[0xcbad] = z80_op_nop,
[0xcbae] = z80_op_nop,
[0xcbaf] = z80_op_nop,
[0xcbb0] = z80_op_nop,
[0xcbb1] = z80_op_nop,
[0xcbb2] = z80_op_nop,
[0xcbb3] = z80_op_nop,
[0xcbb4] = z80_op_nop,
[0xcbb5] = z80_op_nop,
[0xcbb6] = z80_op_nop,
[0xcbb7] = z80_op_nop,
[0xcbb8] = z80_op_nop,
[0xcbb9] = z80_op_nop,
[0xcbba] = z80_op_nop,
[0xcbbb] = z80_op_nop,
[0xcbbc] = z80_op_nop,
[0xcbbd] = z80_op_nop,
[0xcbbe] = z80_op_nop,
[0xcbbf] = z80_op_nop,
[0xcbc0] = z80_op_nop,
[0xcbc1] = z80_op_nop,
[0xcbc2] = z80_op_nop,
[0xcbc3] = z80_op_nop,
[0xcbc4] = z80_op_nop,
[0xcbc5] = z80_op_nop,
[0xcbc6] = z80_op_nop,
[0xcbc7] = z80_op_nop,
[0xcbc8] = z80_op_nop,
[0xcbc9] = z80_op_nop,
[0xcbca] = z80_op_nop,
[0xcbcb] = z80_op_nop,
[0xcbcc] = z80_op_nop,
[0xcbcd] = z80_op_nop,
[0xcbce] = z80_op_nop,
[0xcbcf] = z80_op_nop,
[0xcbd0] = z80_op_nop,
[0xcbd1] = z80_op_nop,
[0xcbd2] = z80_op_nop,
[0xcbd3] = z80_op_nop,
[0xcbd4] = z80_op_nop,
[0xcbd5] = z80_op_nop,
[0xcbd6] = z80_op_nop,
[0xcbd7] = z80_op_nop,
[0xcbd8] = z80_op_nop,
[0xcbd9] = z80_op_nop,
[0xcbda] = z80_op_nop,
[0xcbdb] = z80_op_nop,
[0xcbdc] = z80_op_nop,
[0xcbdd] = z80_op_nop,
[0xcbde] = z80_op_nop,
[0xcbdf] = z80_op_nop,
[0xcbe0] = z80_op_nop,
[0xcbe1] = z80_op_nop,
[0xcbe2] = z80_op_nop,
[0xcbe3] = z80_op_nop,
[0xcbe4] = z80_op_nop,
[0xcbe5] = z80_op_nop,
[0xcbe6] = z80_op_nop,
[0xcbe7] = z80_op_nop,
[0xcbe8] = z80_op_nop,
[0xcbe9] = z80_op_nop,
[0xcbea] = z80_op_nop,
[0xcbeb] = z80_op_nop,
[0xcbec] = z80_op_nop,
[0xcbed] = z80_op_nop,
[0xcbee] = z80_op_nop,
[0xcbef] = z80_op_nop,
[0xcbf0] = z80_op_nop,
[0xcbf1] = z80_op_nop,
[0xcbf2] = z80_op_nop,
[0xcbf3] = z80_op_nop,
[0xcbf4] = z80_op_nop,
[0xcbf5] = z80_op_nop,
[0xcbf6] = z80_op_nop,
[0xcbf7] = z80_op_nop,
[0xcbf8] = z80_op_nop,
[0xcbf9] = z80_op_nop,
[0xcbfa] = z80_op_nop,
[0xcbfb] = z80_op_nop,
[0xcbfc] = z80_op_nop,
[0xcbfd] = z80_op_nop,
[0xcbfe] = z80_op_nop,
[0xcbff] = z80_op_nop,
[0x00cc] = z80_op_nop,
[0x00cd] = z80_op_nop,
[0x00ce] = z80_op_nop,
[0x00cf] = z80_op_nop,
[0x00d0] = z80_op_nop,
[0x00d1] = z80_op_nop,
[0x00d2] = z80_op_nop,
[0x00d3] = z80_op_nop,
[0x00d4] = z80_op_nop,
[0x00d5] = z80_op_nop,
[0x00d6] = z80_op_nop,
[0x00d7] = z80_op_nop,
[0x00d8] = z80_op_nop,
[0x00d9] = z80_op_nop,
[0x00da] = z80_op_nop,
[0x00db] = z80_op_nop,
[0x00dc] = z80_op_nop,
[0xdd09] = z80_op_nop,
[0xdd19] = z80_op_nop,
[0xdd21] = z80_op_nop,
[0xdd22] = z80_op_nop,
[0xdd23] = z80_op_nop,
[0xdd29] = z80_op_nop,
[0xdd2a] = z80_op_nop,
[0xdd2b] = z80_op_nop,
[0xdd34] = z80_op_nop,
[0xdd35] = z80_op_nop,
[0xdd36] = z80_op_nop,
[0xdd39] = z80_op_nop,
[0xdd46] = z80_op_nop,
[0xdd4e] = z80_op_nop,
[0xdd56] = z80_op_nop,
[0xdd5e] = z80_op_nop,
[0xdd66] = z80_op_nop,
[0xdd6e] = z80_op_nop,
[0xdd70] = z80_op_nop,
[0xdd71] = z80_op_nop,
[0xdd72] = z80_op_nop,
[0xdd73] = z80_op_nop,
[0xdd74] = z80_op_nop,
[0xdd75] = z80_op_nop,
[0xdd77] = z80_op_nop,
[0xdd7e] = z80_op_nop,
[0xdd86] = z80_op_nop,
[0xdd8e] = z80_op_nop,
[0xdd96] = z80_op_nop,
[0xdd9e] = z80_op_nop,
[0xdda6] = z80_op_nop,
[0xddae] = z80_op_nop,
[0xddb6] = z80_op_nop,
[0xddbe] = z80_op_nop,
[0xddcb] = z80_op_nop,
[0xdde1] = z80_op_nop,
[0xdde3] = z80_op_nop,
[0xdde5] = z80_op_nop,
[0xdde9] = z80_op_nop,
[0xddf9] = z80_op_nop,
[0x00de] = z80_op_nop,
[0x00df] = z80_op_nop,
[0x00e0] = z80_op_nop,
[0x00e1] = z80_op_nop,
[0x00e2] = z80_op_nop,
[0x00e3] = z80_op_nop,
[0x00e4] = z80_op_nop,
[0x00e5] = z80_op_nop,
[0x00e6] = z80_op_nop,
[0x00e7] = z80_op_nop,
[0x00e8] = z80_op_nop,
[0x00e9] = z80_op_nop,
[0x00ea] = z80_op_nop,
[0x00eb] = z80_op_nop,
[0x00ec] = z80_op_nop,
[0xed40] = z80_op_nop,
[0xed41] = z80_op_nop,
[0xed42] = z80_op_nop,
[0xed43] = z80_op_nop,
[0xed44] = z80_op_nop,
[0xed45] = z80_op_nop,
[0xed46] = z80_op_nop,
[0xed47] = z80_op_nop,
[0xed48] = z80_op_nop,
[0xed49] = z80_op_nop,
[0xed4a] = z80_op_nop,
[0xed4b] = z80_op_nop,
[0xed4d] = z80_op_nop,
[0xed4f] = z80_op_nop,
[0xed50] = z80_op_nop,
[0xed51] = z80_op_nop,
[0xed52] = z80_op_nop,
[0xed53] = z80_op_nop,
[0xed56] = z80_op_nop,
[0xed57] = z80_op_nop,
[0xed58] = z80_op_nop,
[0xed59] = z80_op_nop,
[0xed5a] = z80_op_nop,
[0xed5b] = z80_op_nop,
[0xed5e] = z80_op_nop,
[0xed5f] = z80_op_nop,
[0xed60] = z80_op_nop,
[0xed61] = z80_op_nop,
[0xed62] = z80_op_nop,
[0xed63] = z80_op_nop,
[0xed67] = z80_op_nop,
[0xed68] = z80_op_nop,
[0xed69] = z80_op_nop,
[0xed6a] = z80_op_nop,
[0xed6b] = z80_op_nop,
[0xed6f] = z80_op_nop,
[0xed72] = z80_op_nop,
[0xed73] = z80_op_nop,
[0xed78] = z80_op_nop,
[0xed79] = z80_op_nop,
[0xed7a] = z80_op_nop,
[0xed7b] = z80_op_nop,
[0xeda0] = z80_op_nop,
[0xeda1] = z80_op_nop,
[0xeda2] = z80_op_nop,
[0xeda3] = z80_op_nop,
[0xeda8] = z80_op_nop,
[0xeda9] = z80_op_nop,
[0xedaa] = z80_op_nop,
[0xedab] = z80_op_nop,
[0xedb0] = z80_op_nop,
[0xedb1] = z80_op_nop,
[0xedb2] = z80_op_nop,
[0xedb3] = z80_op_nop,
[0xedb8] = z80_op_nop,
[0xedb9] = z80_op_nop,
[0xedba] = z80_op_nop,
[0xedbb] = z80_op_nop,
[0x00ee] = z80_op_nop,
[0x00ef] = z80_op_nop,
[0x00f0] = z80_op_nop,
[0x00f1] = z80_op_nop,
[0x00f2] = z80_op_nop,
[0x00f3] = z80_op_nop,
[0x00f4] = z80_op_nop,
[0x00f5] = z80_op_nop,
[0x00f6] = z80_op_nop,
[0x00f7] = z80_op_nop,
[0x00f8] = z80_op_nop,
[0x00f9] = z80_op_nop,
[0x00fa] = z80_op_nop,
[0x00fb] = z80_op_nop,
[0x00fc] = z80_op_nop,
[0xfd09] = z80_op_nop,
[0xfd19] = z80_op_nop,
[0xfd21] = z80_op_nop,
[0xfd22] = z80_op_nop,
[0xfd23] = z80_op_nop,
[0xfd29] = z80_op_nop,
[0xfd2a] = z80_op_nop,
[0xfd2b] = z80_op_nop,
[0xfd34] = z80_op_nop,
[0xfd35] = z80_op_nop,
[0xfd36] = z80_op_nop,
[0xfd39] = z80_op_nop,
[0xfd46] = z80_op_nop,
[0xfd4e] = z80_op_nop,
[0xfd56] = z80_op_nop,
[0xfd5e] = z80_op_nop,
[0xfd66] = z80_op_nop,
[0xfd6e] = z80_op_nop,
[0xfd70] = z80_op_nop,
[0xfd71] = z80_op_nop,
[0xfd72] = z80_op_nop,
[0xfd73] = z80_op_nop,
[0xfd74] = z80_op_nop,
[0xfd75] = z80_op_nop,
[0xfd77] = z80_op_nop,
[0xfd7e] = z80_op_nop,
[0xfd86] = z80_op_nop,
[0xfd8e] = z80_op_nop,
[0xfd96] = z80_op_nop,
[0xfd9e] = z80_op_nop,
[0xfda6] = z80_op_nop,
[0xfdae] = z80_op_nop,
[0xfdb6] = z80_op_nop,
[0xfdbe] = z80_op_nop,
[0xfdcb] = z80_op_nop,
[0xfde1] = z80_op_nop,
[0xfde3] = z80_op_nop,
[0xfde5] = z80_op_nop,
[0xfde9] = z80_op_nop,
[0xfdf9] = z80_op_nop,
[0x00fe] = z80_op_nop,
[0x00ff] = z80_op_nop,
/* end generated code */
};

static char* z80_disasm_table[] = {
/* Generated from z80_gen */
[0x0000] = "NOP",
[0x0001] = "LD BC, nn",
[0x0002] = "LD (BC), A",
[0x0003] = "INC BC",
[0x0004] = "INC B",
[0x0005] = "DEC B",
[0x0006] = "LD B, n",
[0x0007] = "RLCA",
[0x0008] = "EX AF, AF'",
[0x0009] = "ADD HL, BC",
[0x000a] = "LD A, (BC)",
[0x000b] = "DEC BC",
[0x000c] = "INC C",
[0x000d] = "DEC C",
[0x000e] = "LD C, n",
[0x000f] = "RRCA",
[0x0010] = "DJNZ PC + n",
[0x0011] = "LD DE, nn",
[0x0012] = "LD (DE), A",
[0x0013] = "INC DE",
[0x0014] = "INC D",
[0x0015] = "DEC D",
[0x0016] = "LD D, n",
[0x0017] = "RLA",
[0x0018] = "JR PC + n",
[0x0019] = "ADD HL, DE",
[0x001a] = "LD A, (DE)",
[0x001b] = "DEC DE",
[0x001c] = "INC E",
[0x001d] = "DEC E",
[0x001e] = "LD E, n",
[0x001f] = "RRA",
[0x0020] = "JR NZ, PC + n",
[0x0021] = "LD HL, nn",
[0x0022] = "LD (nn), HL",
[0x0023] = "INC HL",
[0x0024] = "INC H",
[0x0025] = "DEC H",
[0x0026] = "LD H, n",
[0x0027] = "DAA",
[0x0028] = "JR Z, PC + n",
[0x0029] = "ADD HL, HL",
[0x002a] = "LD HL, (nn)",
[0x002b] = "DEC HL",
[0x002c] = "INC L",
[0x002d] = "DEC L",
[0x002e] = "LD L, n",
[0x002f] = "CPL",
[0x0030] = "JR NC, PC + n",
[0x0031] = "LD SP, nn",
[0x0032] = "LD (nn), A",
[0x0033] = "INC SP",
[0x0034] = "INC (HL)",
[0x0035] = "DEC (HL)",
[0x0036] = "LD (HL), n",
[0x0037] = "SCF",
[0x0038] = "JR Cy, PC + n",
[0x0039] = "ADD HL, SP",
[0x003a] = "LD A, (nn)",
[0x003b] = "DEC SP",
[0x003c] = "INC A",
[0x003d] = "DEC A",
[0x003e] = "LD A, n",
[0x003f] = "CCF",
[0x0040] = "LD B, B",
[0x0041] = "LD B, C",
[0x0042] = "LD B, D",
[0x0043] = "LD B, E",
[0x0044] = "LD B, H",
[0x0045] = "LD B, L",
[0x0046] = "LD B, (HL)",
[0x0047] = "LD B, A",
[0x0048] = "LD C, B",
[0x0049] = "LD C, C",
[0x004a] = "LD C, D",
[0x004b] = "LD C, E",
[0x004c] = "LD C, H",
[0x004d] = "LD C, L",
[0x004e] = "LD C, (HL)",
[0x004f] = "LD C, A",
[0x0050] = "LD D, B",
[0x0051] = "LD D, C",
[0x0052] = "LD D, D",
[0x0053] = "LD D, E",
[0x0054] = "LD D, H",
[0x0055] = "LD D, L",
[0x0056] = "LD D, (HL)",
[0x0057] = "LD D, A",
[0x0058] = "LD E, B",
[0x0059] = "LD E, C",
[0x005a] = "LD E, D",
[0x005b] = "LD E, E",
[0x005c] = "LD E, H",
[0x005d] = "LD E, L",
[0x005e] = "LD E, (HL)",
[0x005f] = "LD E, A",
[0x0060] = "LD H, B",
[0x0061] = "LD H, C",
[0x0062] = "LD H, D",
[0x0063] = "LD H, E",
[0x0064] = "LD H, H",
[0x0065] = "LD H, L",
[0x0066] = "LD H, (HL)",
[0x0067] = "LD H, A",
[0x0068] = "LD L, B",
[0x0069] = "LD L, C",
[0x006a] = "LD L, D",
[0x006b] = "LD L, E",
[0x006c] = "LD L, H",
[0x006d] = "LD L, L",
[0x006e] = "LD L, (HL)",
[0x006f] = "LD L, A",
[0x0070] = "LD (HL), B",
[0x0071] = "LD (HL), C",
[0x0072] = "LD (HL), D",
[0x0073] = "LD (HL), E",
[0x0074] = "LD (HL), H",
[0x0075] = "LD (HL), L",
[0x0076] = "HALT",
[0x0077] = "LD (HL), A",
[0x0078] = "LD A, B",
[0x0079] = "LD A, C",
[0x007a] = "LD A, D",
[0x007b] = "LD A, E",
[0x007c] = "LD A, H",
[0x007d] = "LD A, L",
[0x007e] = "LD A, (HL)",
[0x007f] = "LD A, A",
[0x0080] = "ADD A, B",
[0x0081] = "ADD A, C",
[0x0082] = "ADD A, D",
[0x0083] = "ADD A, E",
[0x0084] = "ADD A, H",
[0x0085] = "ADD A, L",
[0x0086] = "ADD A, (HL)",
[0x0087] = "ADD A, A",
[0x0088] = "ADC A, B",
[0x0089] = "ADC A, C",
[0x008a] = "ADC A, D",
[0x008b] = "ADC A, E",
[0x008c] = "ADC A, H",
[0x008d] = "ADC A, L",
[0x008e] = "ADC A, (HL)",
[0x008f] = "ADC A, A",
[0x0090] = "SUB B",
[0x0091] = "SUB C",
[0x0092] = "SUB D",
[0x0093] = "SUB E",
[0x0094] = "SUB H",
[0x0095] = "SUB L",
[0x0096] = "SUB (HL)",
[0x0097] = "SUB A",
[0x0098] = "SBC A, B",
[0x0099] = "SBC A, C",
[0x009a] = "SBC A, D",
[0x009b] = "SBC A, E",
[0x009c] = "SBC A, H",
[0x009d] = "SBC A, L",
[0x009e] = "SBC A, (HL)",
[0x009f] = "SBC A, A",
[0x00a0] = "AND B",
[0x00a1] = "AND C",
[0x00a2] = "AND D",
[0x00a3] = "AND E",
[0x00a4] = "AND H",
[0x00a5] = "AND L",
[0x00a6] = "AND (HL)",
[0x00a7] = "AND A",
[0x00a8] = "XOR B",
[0x00a9] = "XOR C",
[0x00aa] = "XOR D",
[0x00ab] = "XOR E",
[0x00ac] = "XOR H",
[0x00ad] = "XOR L",
[0x00ae] = "XOR (HL)",
[0x00af] = "XOR A",
[0x00b0] = "OR B",
[0x00b1] = "OR C",
[0x00b2] = "OR D",
[0x00b3] = "OR E",
[0x00b4] = "OR H",
[0x00b5] = "OR L",
[0x00b6] = "OR (HL)",
[0x00b7] = "OR A",
[0x00b8] = "CP B",
[0x00b9] = "CP C",
[0x00ba] = "CP D",
[0x00bb] = "CP E",
[0x00bc] = "CP H",
[0x00bd] = "CP L",
[0x00be] = "CP (HL)",
[0x00bf] = "CP A",
[0x00c0] = "RET NZ",
[0x00c1] = "POP BC",
[0x00c2] = "JP NZ, nn",
[0x00c3] = "JP nn",
[0x00c4] = "CALL NZ, nn",
[0x00c5] = "PUSH BC",
[0x00c6] = "ADD A, n",
[0x00c7] = "RST 0h",
[0x00c8] = "RET Z",
[0x00c9] = "RET",
[0x00ca] = "JP Z, nn",
[0xcb00] = "RLC B",
[0xcb01] = "RLC C",
[0xcb02] = "RLC D",
[0xcb03] = "RLC E",
[0xcb04] = "RLC H",
[0xcb05] = "RLC L",
[0xcb06] = "RLC (HL)",
[0xcb07] = "RLC A",
[0xcb08] = "RRC B",
[0xcb09] = "RRC C",
[0xcb0a] = "RRC D",
[0xcb0b] = "RRC E",
[0xcb0c] = "RRC H",
[0xcb0d] = "RRC L",
[0xcb0e] = "RRC (HL)",
[0xcb0f] = "RRC A",
[0xcb10] = "RL B",
[0xcb11] = "RL C",
[0xcb12] = "RL D",
[0xcb13] = "RL E",
[0xcb14] = "RL H",
[0xcb15] = "RL L",
[0xcb16] = "RL (HL)",
[0xcb17] = "RL A",
[0xcb18] = "RR B",
[0xcb19] = "RR C",
[0xcb1a] = "RR D",
[0xcb1b] = "RR E",
[0xcb1c] = "RR H",
[0xcb1d] = "RR L",
[0xcb1e] = "RR (HL)",
[0xcb1f] = "RR A",
[0xcb20] = "SLA B",
[0xcb21] = "SLA C",
[0xcb22] = "SLA D",
[0xcb23] = "SLA E",
[0xcb24] = "SLA H",
[0xcb25] = "SLA L",
[0xcb26] = "SLA (HL)",
[0xcb27] = "SLA A",
[0xcb28] = "SRA B",
[0xcb29] = "SRA C",
[0xcb2a] = "SRA D",
[0xcb2b] = "SRA E",
[0xcb2c] = "SRA H",
[0xcb2d] = "SRA L",
[0xcb2e] = "SRA (HL)",
[0xcb2f] = "SRA A",
[0xcb38] = "SRL B",
[0xcb39] = "SRL C",
[0xcb3a] = "SRL D",
[0xcb3b] = "SRL E",
[0xcb3c] = "SRL H",
[0xcb3d] = "SRL L",
[0xcb3e] = "SRL (HL)",
[0xcb3f] = "SRL A",
[0xcb40] = "BIT 0, B",
[0xcb41] = "BIT 0, C",
[0xcb42] = "BIT 0, D",
[0xcb43] = "BIT 0, E",
[0xcb44] = "BIT 0, H",
[0xcb45] = "BIT 0, L",
[0xcb46] = "BIT 0, (HL)",
[0xcb47] = "BIT 0, A",
[0xcb48] = "BIT 1, B",
[0xcb49] = "BIT 1, C",
[0xcb4a] = "BIT 1, D",
[0xcb4b] = "BIT 1, E",
[0xcb4c] = "BIT 1, H",
[0xcb4d] = "BIT 1, L",
[0xcb4e] = "BIT 1, (HL)",
[0xcb4f] = "BIT 1, A",
[0xcb50] = "BIT 2, B",
[0xcb51] = "BIT 2, C",
[0xcb52] = "BIT 2, D",
[0xcb53] = "BIT 2, E",
[0xcb54] = "BIT 2, H",
[0xcb55] = "BIT 2, L",
[0xcb56] = "BIT 2, (HL)",
[0xcb57] = "BIT 2, A",
[0xcb58] = "BIT 3, B",
[0xcb59] = "BIT 3, C",
[0xcb5a] = "BIT 3, D",
[0xcb5b] = "BIT 3, E",
[0xcb5c] = "BIT 3, H",
[0xcb5d] = "BIT 3, L",
[0xcb5e] = "BIT 3, (HL)",
[0xcb5f] = "BIT 3, A",
[0xcb60] = "BIT 4, B",
[0xcb61] = "BIT 4, C",
[0xcb62] = "BIT 4, D",
[0xcb63] = "BIT 4, E",
[0xcb64] = "BIT 4, H",
[0xcb65] = "BIT 4, L",
[0xcb66] = "BIT 4, (HL)",
[0xcb67] = "BIT 4, A",
[0xcb68] = "BIT 5, B",
[0xcb69] = "BIT 5, C",
[0xcb6a] = "BIT 5, D",
[0xcb6b] = "BIT 5, E",
[0xcb6c] = "BIT 5, H",
[0xcb6d] = "BIT 5, L",
[0xcb6e] = "BIT 5, (HL)",
[0xcb6f] = "BIT 5, A",
[0xcb70] = "BIT 6, B",
[0xcb71] = "BIT 6, C",
[0xcb72] = "BIT 6, D",
[0xcb73] = "BIT 6, E",
[0xcb74] = "BIT 6, H",
[0xcb75] = "BIT 6, L",
[0xcb76] = "BIT 6, (HL)",
[0xcb77] = "BIT 6, A",
[0xcb78] = "BIT 7, B",
[0xcb79] = "BIT 7, C",
[0xcb7a] = "BIT 7, D",
[0xcb7b] = "BIT 7, E",
[0xcb7c] = "BIT 7, H",
[0xcb7d] = "BIT 7, L",
[0xcb7e] = "BIT 7, (HL)",
[0xcb7f] = "BIT 7, A",
[0xcb80] = "RES 0, B",
[0xcb81] = "RES 0, C",
[0xcb82] = "RES 0, D",
[0xcb83] = "RES 0, E",
[0xcb84] = "RES 0, H",
[0xcb85] = "RES 0, L",
[0xcb86] = "RES 0, (HL)",
[0xcb87] = "RES 0, A",
[0xcb88] = "RES 1, B",
[0xcb89] = "RES 1, C",
[0xcb8a] = "RES 1, D",
[0xcb8b] = "RES 1, E",
[0xcb8c] = "RES 1, H",
[0xcb8d] = "RES 1, L",
[0xcb8e] = "RES 1, (HL)",
[0xcb8f] = "RES 1, A",
[0xcb90] = "RES 2, B",
[0xcb91] = "RES 2, C",
[0xcb92] = "RES 2, D",
[0xcb93] = "RES 2, E",
[0xcb94] = "RES 2, H",
[0xcb95] = "RES 2, L",
[0xcb96] = "RES 2, (HL)",
[0xcb97] = "RES 2, A",
[0xcb98] = "RES 3, B",
[0xcb99] = "RES 3, C",
[0xcb9a] = "RES 3, D",
[0xcb9b] = "RES 3, E",
[0xcb9c] = "RES 3, H",
[0xcb9d] = "RES 3, L",
[0xcb9e] = "RES 3, (HL)",
[0xcb9f] = "RES 3, A",
[0xcba0] = "RES 4, B",
[0xcba1] = "RES 4, C",
[0xcba2] = "RES 4, D",
[0xcba3] = "RES 4, E",
[0xcba4] = "RES 4, H",
[0xcba5] = "RES 4, L",
[0xcba6] = "RES 4, (HL)",
[0xcba7] = "RES 4, A",
[0xcba8] = "RES 5, B",
[0xcba9] = "RES 5, C",
[0xcbaa] = "RES 5, D",
[0xcbab] = "RES 5, E",
[0xcbac] = "RES 5, H",
[0xcbad] = "RES 5, L",
[0xcbae] = "RES 5, (HL)",
[0xcbaf] = "RES 5, A",
[0xcbb0] = "RES 6, B",
[0xcbb1] = "RES 6, C",
[0xcbb2] = "RES 6, D",
[0xcbb3] = "RES 6, E",
[0xcbb4] = "RES 6, H",
[0xcbb5] = "RES 6, L",
[0xcbb6] = "RES 6, (HL)",
[0xcbb7] = "RES 6, A",
[0xcbb8] = "RES 7, B",
[0xcbb9] = "RES 7, C",
[0xcbba] = "RES 7, D",
[0xcbbb] = "RES 7, E",
[0xcbbc] = "RES 7, H",
[0xcbbd] = "RES 7, L",
[0xcbbe] = "RES 7, (HL)",
[0xcbbf] = "RES 7, A",
[0xcbc0] = "SET 0, B",
[0xcbc1] = "SET 0, C",
[0xcbc2] = "SET 0, D",
[0xcbc3] = "SET 0, E",
[0xcbc4] = "SET 0, H",
[0xcbc5] = "SET 0, L",
[0xcbc6] = "SET 0, (HL)",
[0xcbc7] = "SET 0, A",
[0xcbc8] = "SET 1, B",
[0xcbc9] = "SET 1, C",
[0xcbca] = "SET 1, D",
[0xcbcb] = "SET 1, E",
[0xcbcc] = "SET 1, H",
[0xcbcd] = "SET 1, L",
[0xcbce] = "SET 1, (HL)",
[0xcbcf] = "SET 1, A",
[0xcbd0] = "SET 2, B",
[0xcbd1] = "SET 2, C",
[0xcbd2] = "SET 2, D",
[0xcbd3] = "SET 2, E",
[0xcbd4] = "SET 2, H",
[0xcbd5] = "SET 2, L",
[0xcbd6] = "SET 2, (HL)",
[0xcbd7] = "SET 2, A",
[0xcbd8] = "SET 3, B",
[0xcbd9] = "SET 3, C",
[0xcbda] = "SET 3, D",
[0xcbdb] = "SET 3, E",
[0xcbdc] = "SET 3, H",
[0xcbdd] = "SET 3, L",
[0xcbde] = "SET 3, (HL)",
[0xcbdf] = "SET 3, A",
[0xcbe0] = "SET 4, B",
[0xcbe1] = "SET 4, C",
[0xcbe2] = "SET 4, D",
[0xcbe3] = "SET 4, E",
[0xcbe4] = "SET 4, H",
[0xcbe5] = "SET 4, L",
[0xcbe6] = "SET 4, (HL)",
[0xcbe7] = "SET 4, A",
[0xcbe8] = "SET 5, B",
[0xcbe9] = "SET 5, C",
[0xcbea] = "SET 5, D",
[0xcbeb] = "SET 5, E",
[0xcbec] = "SET 5, H",
[0xcbed] = "SET 5, L",
[0xcbee] = "SET 5, (HL)",
[0xcbef] = "SET 5, A",
[0xcbf0] = "SET 6, B",
[0xcbf1] = "SET 6, C",
[0xcbf2] = "SET 6, D",
[0xcbf3] = "SET 6, E",
[0xcbf4] = "SET 6, H",
[0xcbf5] = "SET 6, L",
[0xcbf6] = "SET 6, (HL)",
[0xcbf7] = "SET 6, A",
[0xcbf8] = "SET 7, B",
[0xcbf9] = "SET 7, C",
[0xcbfa] = "SET 7, D",
[0xcbfb] = "SET 7, E",
[0xcbfc] = "SET 7, H",
[0xcbfd] = "SET 7, L",
[0xcbfe] = "SET 7, (HL)",
[0xcbff] = "SET 7, A",
[0x00cc] = "CALL Z, nn",
[0x00cd] = "CALL nn",
[0x00ce] = "ADC A, n",
[0x00cf] = "RST 8h",
[0x00d0] = "RET NC",
[0x00d1] = "POP DE",
[0x00d2] = "JP NC, nn",
[0x00d3] = "OUT (n), A",
[0x00d4] = "CALL NC, nn",
[0x00d5] = "PUSH DE",
[0x00d6] = "SUB n",
[0x00d7] = "RST 10h",
[0x00d8] = "RET Cy",
[0x00d9] = "EXX",
[0x00da] = "JP Cy, nn",
[0x00db] = "IN A, (n)",
[0x00dc] = "CALL Cy, nn",
[0xdd09] = "ADD IX, BC",
[0xdd19] = "ADD IX, DE",
[0xdd21] = "LD IX, nn",
[0xdd22] = "LD (nn), IX",
[0xdd23] = "INC IX",
[0xdd29] = "ADD IX, IX",
[0xdd2a] = "LD IX, (nn)",
[0xdd2b] = "DEC IX",
[0xdd34] = "INC (IX + d)",
[0xdd35] = "DEC (IX + d)",
[0xdd36] = "LD (IX + d), n",
[0xdd39] = "ADD IX, SP",
[0xdd46] = "LD B, (IX + d)",
[0xdd4e] = "LD C, (IX + d)",
[0xdd56] = "LD D, (IX + d)",
[0xdd5e] = "LD E, (IX + d)",
[0xdd66] = "LD H, (IX + d)",
[0xdd6e] = "LD L, (IX + d)",
[0xdd70] = "LD (IX + d), B",
[0xdd71] = "LD (IX + d), C",
[0xdd72] = "LD (IX + d), D",
[0xdd73] = "LD (IX + d), E",
[0xdd74] = "LD (IX + d), H",
[0xdd75] = "LD (IX + d), L",
[0xdd77] = "LD (IX + d), A",
[0xdd7e] = "LD A, (IX + d)",
[0xdd86] = "ADD A, (IX + d)",
[0xdd8e] = "ADC A, (IX + d)",
[0xdd96] = "SUB (IX + d)",
[0xdd9e] = "SBC A, (IX + d)",
[0xdda6] = "AND (IX + d)",
[0xddae] = "XOR (IX + d)",
[0xddb6] = "OR (IX + d)",
[0xddbe] = "CP (IX + d)",
[0xddcb] = "RLC (IX + d)",
/* [0xddcb] = "RRC (IX + d)", */
/* [0xddcb] = "RL (IX + d)", */
/* [0xddcb] = "RR (IX + d)", */
/* [0xddcb] = "SLA (IX + d)", */
/* [0xddcb] = "SRA (IX + d)", */
/* [0xddcb] = "SRL (IX + d)", */
/* [0xddcb] = "BIT 0, (IX + d)", */
/* [0xddcb] = "BIT 1, (IX + d)", */
/* [0xddcb] = "BIT 2, (IX + d)", */
/* [0xddcb] = "BIT 3, (IX + d)", */
/* [0xddcb] = "BIT 4, (IX + d)", */
/* [0xddcb] = "BIT 5, (IX + d)", */
/* [0xddcb] = "BIT 6, (IX + d)", */
/* [0xddcb] = "BIT 7, (IX + d)", */
/* [0xddcb] = "RES 0, (IX + d)", */
/* [0xddcb] = "RES 1, (IX + d)", */
/* [0xddcb] = "RES 2, (IX + d)", */
/* [0xddcb] = "RES 3, (IX + d)", */
/* [0xddcb] = "RES 4, (IX + d)", */
/* [0xddcb] = "RES 5, (IX + d)", */
/* [0xddcb] = "RES 6, (IX + d)", */
/* [0xddcb] = "RES 7, (IX + d)", */
/* [0xddcb] = "SET 0, (IX + d)", */
/* [0xddcb] = "SET 1, (IX + d)", */
/* [0xddcb] = "SET 2, (IX + d)", */
/* [0xddcb] = "SET 3, (IX + d)", */
/* [0xddcb] = "SET 4, (IX + d)", */
/* [0xddcb] = "SET 5, (IX + d)", */
/* [0xddcb] = "SET 6, (IX + d)", */
/* [0xddcb] = "SET 7, (IX + d)", */
[0xdde1] = "POP IX",
[0xdde3] = "EX (SP), IX",
[0xdde5] = "PUSH IX",
[0xdde9] = "JP (IX)",
[0xddf9] = "LD SP, IX",
[0x00de] = "SBC A, n",
[0x00df] = "RST 18h",
[0x00e0] = "RET PO",
[0x00e1] = "POP HL",
[0x00e2] = "JP PO, nn",
[0x00e3] = "EX (SP), HL",
[0x00e4] = "CALL PO, nn",
[0x00e5] = "PUSH HL",
[0x00e6] = "AND n",
[0x00e7] = "RST 20h",
[0x00e8] = "RET PE",
[0x00e9] = "JP (HL)",
[0x00ea] = "JP PE, (nn)",
[0x00eb] = "EX DE, HL",
[0x00ec] = "CALL PE, nn",
[0xed40] = "IN B, (C)",
[0xed41] = "OUT (C), B",
[0xed42] = "SBC HL, BC",
[0xed43] = "LD (nn), BC",
[0xed44] = "NEG",
[0xed45] = "RETN",
[0xed46] = "IM 0",
[0xed47] = "LD I, A",
[0xed48] = "IN C, (C)",
[0xed49] = "OUT (C), C",
[0xed4a] = "ADC HL, BC",
[0xed4b] = "LD BC, (nn)",
[0xed4d] = "RETI",
[0xed4f] = "LD R, A",
[0xed50] = "IN D, (C)",
[0xed51] = "OUT (C), D",
[0xed52] = "SBC HL, DE",
[0xed53] = "LD (nn), DE",
[0xed56] = "IM 1",
[0xed57] = "LD A, I",
[0xed58] = "IN E, (C)",
[0xed59] = "OUT (C), E",
[0xed5a] = "ADC HL, DE",
[0xed5b] = "LD DE, (nn)",
[0xed5e] = "IM 2",
[0xed5f] = "LD A, R",
[0xed60] = "IN H, (C)",
[0xed61] = "OUT (C), H",
[0xed62] = "SBC HL, HL",
[0xed63] = "LD (nn), HL",
[0xed67] = "RRD",
[0xed68] = "IN L, (C)",
[0xed69] = "OUT (C), L",
[0xed6a] = "ADC HL, HL",
[0xed6b] = "LD HL, (nn)",
[0xed6f] = "RLD",
[0xed72] = "SBC HL, SP",
[0xed73] = "LD (nn), SP",
[0xed78] = "IN A, (C)",
[0xed79] = "OUT (C), A",
[0xed7a] = "ADC HL, SP",
[0xed7b] = "LD SP, (nn)",
[0xeda0] = "LDI",
[0xeda1] = "CPI",
[0xeda2] = "INI",
[0xeda3] = "OUTI",
[0xeda8] = "LDD",
[0xeda9] = "CPD",
[0xedaa] = "IND",
[0xedab] = "OUTD",
[0xedb0] = "LDIR",
[0xedb1] = "CPIR",
[0xedb2] = "INIR",
[0xedb3] = "OTIR",
[0xedb8] = "LDDR",
[0xedb9] = "CPDR",
[0xedba] = "INDR",
[0xedbb] = "OTDR",
[0x00ee] = "XOR n",
[0x00ef] = "RST 28h",
[0x00f0] = "RET P",
[0x00f1] = "POP AF",
[0x00f2] = "JP P, nn",
[0x00f3] = "DI",
[0x00f4] = "CALL P, nn",
[0x00f5] = "PUSH AF",
[0x00f6] = "OR n",
[0x00f7] = "RST 30h",
[0x00f8] = "RET M",
[0x00f9] = "LD SP, HL",
[0x00fa] = "JP M, nn",
[0x00fb] = "EI",
[0x00fc] = "CALL M, nn",
[0xfd09] = "ADD IY, BC",
[0xfd19] = "ADD IY, DE",
[0xfd21] = "LD IY, nn",
[0xfd22] = "LD (nn), IY",
[0xfd23] = "INC IY",
[0xfd29] = "ADD IY, IY",
[0xfd2a] = "LD IY, (nn)",
[0xfd2b] = "DEC IY",
[0xfd34] = "INC (IY + d)",
[0xfd35] = "DEC (IY + d)",
[0xfd36] = "LD (IY + d), n",
[0xfd39] = "ADD IY, SP",
[0xfd46] = "LD B, (IY + d)",
[0xfd4e] = "LD C, (IY + d)",
[0xfd56] = "LD D, (IY + d)",
[0xfd5e] = "LD E, (IY + d)",
[0xfd66] = "LD H, (IY + d)",
[0xfd6e] = "LD L, (IY + d)",
[0xfd70] = "LD (IY + d), B",
[0xfd71] = "LD (IY + d), C",
[0xfd72] = "LD (IY + d), D",
[0xfd73] = "LD (IY + d), E",
[0xfd74] = "LD (IY + d), H",
[0xfd75] = "LD (IY + d), L",
[0xfd77] = "LD (IY + d), A",
[0xfd7e] = "LD A, (IY + d)",
[0xfd86] = "ADD A, (IY + d)",
[0xfd8e] = "ADC A, (IY + d)",
[0xfd96] = "SUB (IY + d)",
[0xfd9e] = "SBC A, (IY + d)",
[0xfda6] = "AND (IY + d)",
[0xfdae] = "XOR (IY + d)",
[0xfdb6] = "OR (IY + d)",
[0xfdbe] = "CP (IY + d)",
[0xfdcb] = "RLC (IY + d)",
/* [0xfdcb] = "RRC (IY + d)", */
/* [0xfdcb] = "RL (IY + d)", */
/* [0xfdcb] = "RR (IY + d)", */
/* [0xfdcb] = "SLA (IY + d)", */
/* [0xfdcb] = "SRA (IY + d)", */
/* [0xfdcb] = "SRL (IY + d)", */
/* [0xfdcb] = "BIT 0, (IY + d)", */
/* [0xfdcb] = "BIT 1, (IY + d)", */
/* [0xfdcb] = "BIT 2, (IY + d)", */
/* [0xfdcb] = "BIT 3, (IY + d)", */
/* [0xfdcb] = "BIT 4, (IY + d)", */
/* [0xfdcb] = "BIT 5, (IY + d)", */
/* [0xfdcb] = "BIT 6, (IY + d)", */
/* [0xfdcb] = "BIT 7, (IY + d)", */
/* [0xfdcb] = "RES 0, (IY + d)", */
/* [0xfdcb] = "RES 1, (IY + d)", */
/* [0xfdcb] = "RES 2, (IY + d)", */
/* [0xfdcb] = "RES 3, (IY + d)", */
/* [0xfdcb] = "RES 4, (IY + d)", */
/* [0xfdcb] = "RES 5, (IY + d)", */
/* [0xfdcb] = "RES 6, (IY + d)", */
/* [0xfdcb] = "RES 7, (IY + d)", */
/* [0xfdcb] = "SET 0, (IY + d)", */
/* [0xfdcb] = "SET 1, (IY + d)", */
/* [0xfdcb] = "SET 2, (IY + d)", */
/* [0xfdcb] = "SET 3, (IY + d)", */
/* [0xfdcb] = "SET 4, (IY + d)", */
/* [0xfdcb] = "SET 5, (IY + d)", */
/* [0xfdcb] = "SET 6, (IY + d)", */
/* [0xfdcb] = "SET 7, (IY + d)", */
[0xfde1] = "POP IY",
[0xfde3] = "EX (SP), IY",
[0xfde5] = "PUSH IY",
[0xfde9] = "JP (IY)",
[0xfdf9] = "LD SP, IY",
[0x00fe] = "CP n",
[0x00ff] = "RST 38h",
/* end generated code */
};
