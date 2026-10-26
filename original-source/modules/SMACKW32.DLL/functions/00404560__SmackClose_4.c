/*
 * _SmackClose@4 at 00404560
 * undefined __stdcall _SmackClose@4(undefined4 * param_1)
 * Address ranges: 00404560-0040469c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackClose_4(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
                    /* 0x4560  18  _SmackClose@4 */
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[0x108] != -1) {
      puVar3 = param_1;
      do {
        if (puVar3[0x101] != 0) {
          (*DAT_0041047c)(puVar3[0x101]);
          FUN_00402c10();
          FUN_00402c10();
          DAT_0040e83c = DAT_0040e83c + -1;
          puVar3[0x101] = 0;
        }
        puVar3 = puVar3 + 1;
      } while (puVar3 != param_1 + 7);
      param_1[0x108] = 0xffffffff;
    }
    iVar2 = DAT_0040e83c;
    if ((DAT_0040e83c == 0) && (DAT_0040e840 != 0)) {
      FUN_00402c10();
      DAT_0040e840 = iVar2;
    }
    if (((HANDLE)param_1[0xe5] != (HANDLE)0xffffffff) &&
       ((*(byte *)((int)param_1 + 0x385) & 0x10) == 0)) {
      CloseHandle((HANDLE)param_1[0xe5]);
    }
    if (param_1[0xe8] != 0) {
      FUN_00402c10();
    }
    if (param_1[0xe7] != 0) {
      FUN_00402c10();
    }
    if (param_1[0xef] != 0) {
      FUN_00402c10();
    }
    if (param_1[0xeb] != 0) {
      FUN_00402c10();
    }
    if (param_1[0x10b] != 0) {
      FUN_00402c10();
    }
    uVar1 = param_1[0xe1];
    for (iVar2 = 299; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
    if ((uVar1 & 0x2000000) == 0) {
      FUN_00402c10();
    }
  }
  return;
}

