from docx.shared import Mm
from docxtpl import DocxTemplate, InlineImage

#Importação do doc que será usado como template
doc = DocxTemplate("media/editavel.docx")

# Trocar informações pelas do modelo
context = {
    "nomeAluno": 'Lucas de Lima Chaves',
    "mesReferencia": 'janeiro',
    "nomeDisciplina": 'Fundamentos',
    "dataInicio": '22/04/2022',
    "dataFim": '22/05/2022',
    "descricaoAtividades": 'lorem ipsun loerelorem ipsun loerelorem ipsun loerelorem ipsun loerelorem ipsun loerelorem ipsun loerelorem ipsun loerelorem ',
}

# Trocar assinatura do aluno e tutor, pelas do modelo
doc.replace_pic('Imagem 10', 'assinaturas/assinaturaAluno.png')
doc.replace_pic('Imagem 12', 'assinaturas/assinaturaLeandro.jpeg')

# doc.replace_media('media/assinaturaModelo2.png', 'assinaturas/assinaturaAluno.png')

# Aplicar a troca de informações
doc.render(context)

#Gerar documento
doc.save("relatorios/teste.docx")
