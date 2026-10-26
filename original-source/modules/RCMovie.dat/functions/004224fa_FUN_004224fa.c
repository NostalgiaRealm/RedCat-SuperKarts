/*
 * FUN_004224fa at 004224fa
 * undefined __thiscall FUN_004224fa(void * this, char * param_1)
 * Address ranges: 004224fa-00422553
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004224fa(void *this,char *param_1)

{
  char cVar1;
  char cVar2;
  undefined *this_00;
  uint uVar3;
  undefined *puVar4;
  
  this_00 = (undefined *)(int)*param_1;
  uVar3 = FUN_004255e3(this,(uint)this_00);
  if (uVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_0043746c < 2) {
        uVar3 = (byte)PTR_DAT_00437260[*param_1 * 2] & 4;
        this_00 = PTR_DAT_00437260;
      }
      else {
        puVar4 = (undefined *)0x4;
        uVar3 = FUN_0042240c(this_00,(int)*param_1,4);
        this_00 = puVar4;
      }
    } while (uVar3 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_00437470;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}

