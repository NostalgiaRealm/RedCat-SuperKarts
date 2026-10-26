/*
 * FUN_00449970 at 00449970
 * undefined FUN_00449970(void)
 * Address ranges: 00449970-00449a6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00449970(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char local_40 [64];
  
  iVar2 = FUN_004b1f60(param_2,0);
  if (*param_1 != 0) {
    FUN_00449930();
  }
  pvVar3 = operator_new(iVar2 * 4);
  *param_1 = (int)pvVar3;
  FUN_00492fe0(pvVar3 != (void *)0x0,s__s___d__Could_not_allocate_nuber_004f019c,
               s_D__work_rcsk_Code_game_anm_type__004f0178,0x90,iVar2);
  iVar6 = 0;
  if (iVar2 < 1) {
    param_1[1] = iVar2;
    return;
  }
  do {
    FUN_004b2110(iVar6,local_40,0x3f);
    uVar4 = 0xffffffff;
    pcVar7 = local_40;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    pvVar3 = operator_new(~uVar4);
    *(void **)(*param_1 + iVar6 * 4) = pvVar3;
    FUN_00492fe0(*(int *)(*param_1 + iVar6 * 4) != 0,s__s___d__Could_not_allocate_name__004f0208,
                 s_D__work_rcsk_Code_game_anm_type__004f01e4,0x9b,~uVar4,iVar6);
    uVar4 = 0xffffffff;
    pcVar7 = local_40;
    do {
      pcVar8 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar7 = pcVar8 + -uVar4;
    pcVar8 = *(char **)(*param_1 + iVar6 * 4);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    iVar6 = iVar6 + 1;
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    if (iVar2 <= iVar6) {
      param_1[1] = iVar2;
      return;
    }
  } while( true );
}

