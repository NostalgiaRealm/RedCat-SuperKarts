/*
 * FUN_0048bf80 at 0048bf80
 * undefined FUN_0048bf80(void)
 * Address ranges: 0048bf80-0048c02b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0048bf80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = DAT_00680ae4;
  iVar4 = param_1;
  iVar5 = DAT_00680af0;
  while( true ) {
    if (param_2 == 0) {
      iVar4 = iVar4 + 1;
    }
    else if (param_2 == 1) {
      iVar4 = iVar4 + -1;
    }
    else {
      FUN_004afee0(s__s__d___Illegal_spawntype__d_004f9ffc,
                   s_D__work_rcsk_Code_game_rse_spawn_004f9fd4,0x29,param_2);
      iVar3 = DAT_00680ae4;
      iVar5 = DAT_00680af0;
    }
    iVar2 = -1;
    iVar1 = 0;
    if (0 < iVar3) {
      do {
        if (*(char *)(iVar5 + iVar1) == '\x01') {
          iVar2 = iVar1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar3);
    }
    if (iVar2 < iVar4) {
      iVar4 = 0;
    }
    else if (iVar4 < 0) {
      iVar4 = -1;
      iVar2 = 0;
      if (0 < iVar3) {
        do {
          if (*(char *)(iVar5 + iVar2) == '\x01') {
            iVar4 = iVar2;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar3);
      }
    }
    if (*(int *)(iVar4 * 0x50 + 4 + DAT_00680ae0) == 0x33) break;
    if (iVar4 == param_1) {
      return -1;
    }
  }
  return iVar4;
}

