/*
 * FUN_00418590 at 00418590
 * undefined FUN_00418590(void)
 * Address ranges: 00418590-004186b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00418590(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 local_124;
  undefined1 local_120 [16];
  CHAR local_110 [16];
  char local_100 [128];
  undefined1 local_80 [128];
  
  FUN_004b1f10(param_2,s_Cylinders_004e14d0,local_100,0x7f);
  iVar5 = -1;
  pcVar6 = local_100;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  if (iVar5 != -2) {
    iVar5 = FUN_004b1f60(local_100,0);
    iVar7 = 0;
    if (0 < iVar5) {
      do {
        FUN_004b2110(iVar7,local_80,0x7f);
        local_124 = FUN_0049de80(local_80);
        iVar2 = FUN_0049dd20(local_124);
        puVar3 = *(undefined1 **)(iVar2 + 0x1c);
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_004d2404;
        }
        uVar4 = FUN_004b51e0(puVar3,0);
        *(undefined4 *)(iVar2 + 0x38) = uVar4;
        FUN_00459170(*(undefined4 *)(param_1[0x13] + 8),1,&local_124);
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar5);
      if ((0 < iVar5) && (iVar5 = 0, 0 < *param_1)) {
        do {
          wsprintfA(local_110,&DAT_004e14e0,&DAT_004e14dc,iVar5);
          FUN_004181d0(param_2,local_110,local_120);
          FUN_00418ef0(*(undefined4 *)(param_1[0x15] + 8),1,local_120);
          iVar5 = iVar5 + 1;
        } while (iVar5 < *param_1);
      }
    }
  }
  return;
}

