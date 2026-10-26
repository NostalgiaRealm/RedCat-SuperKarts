/*
 * FUN_0040d310 at 0040d310
 * undefined FUN_0040d310(void)
 * Address ranges: 0040d310-0040d471
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d310(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar6 = param_1 * 0x11c;
  if ((&DAT_00503ef4)[param_1 * 0x47] != 9) {
    if ((&DAT_00503ef4)[param_1 * 0x47] == 0x19) {
      FUN_004126b0(param_1,&DAT_00503ef0 + param_1 * 0x47);
    }
    FUN_0040f380(param_1);
    puVar7 = (undefined4 *)(&DAT_00503f90 + iVar6);
    for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *param_2;
      param_2 = param_2 + 1;
      puVar7 = puVar7 + 1;
    }
    uVar2 = FUN_0040c8f0();
    uVar3 = FUN_0040c900();
    uVar4 = FUN_0040c940();
    FUN_0040d260(param_1,uVar4);
    FUN_0040ddd0(param_1);
    switch(uVar2) {
    case 1:
      FUN_00411830(param_1,&DAT_00503ef0 + param_1 * 0x47,uVar3);
      (&DAT_00503ef4)[param_1 * 0x47] = 0x19;
      return;
    case 2:
      FUN_00411b40(param_1,&DAT_00503ef0 + param_1 * 0x47,uVar3);
      (&DAT_00503ef4)[param_1 * 0x47] = 0x19;
      return;
    case 3:
      FUN_00411e50(param_1,&DAT_00503ef0 + param_1 * 0x47,uVar3);
      (&DAT_00503ef4)[param_1 * 0x47] = 0x19;
      return;
    case 4:
      FUN_00412090(param_1,&DAT_00503ef0 + param_1 * 0x47,uVar3);
      (&DAT_00503ef4)[param_1 * 0x47] = 0x19;
      return;
    default:
      *(undefined4 *)(&DAT_00503f60 + iVar6) = 8;
      *(undefined4 *)(&DAT_00503f88 + iVar6) = 0;
      FUN_0040c960(3);
      cVar1 = FUN_0040c9b0();
      if (cVar1 != '\0') {
        FUN_004afce0(s___Attacked_by_redcat_with_NOTHIN_004defa8);
      }
    }
    (&DAT_00503ef4)[param_1 * 0x47] = 0x19;
  }
  return;
}

