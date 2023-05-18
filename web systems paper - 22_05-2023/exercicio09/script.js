// SCRIPT: formulario nome, email e idade

const form = document.getElementById('myForm');
    const nomeInput = document.getElementById('nome');
    const idadeInput = document.getElementById('idade');
    const emailInput = document.getElementById('email');

    form.addEventListener('submit', function(event) {
      event.preventDefault();
      if (!validateNome()) {
        return;
      }
      if (!validateIdade()) {
        return;
      }
      if (!validateEmail()) {
        return;
      }
      // Se chegou até aqui, os campos foram validados com sucesso
      // Você pode enviar o formulário ou executar outras ações aqui
      alert('Formulário enviado com sucesso!');
      form.reset();
    });

    function validateNome() {
      const nome = nomeInput.value.trim();
      if (nome === '') {
        nomeError.textContent = 'Por favor, insira seu nome.';
        return false;
      }
      return true;
    }

    function validateIdade() {
      const idade = idadeInput.value.trim();
      if (idade === '') {
        idadeError.textContent = 'Por favor, insira sua idade.';
        return false;
      }
      if (isNaN(idade) || idade < 0) {
        idadeError.textContent = 'Por favor, insira uma idade válida.';
        return false;
      }
      return true;
    }

    function validateEmail() {
      const email = emailInput.value.trim();
      if (email === '') {
        emailError.textContent = 'Por favor, insira seu e-mail.';
        return false;
      }
      
      // Aqui está uma expressão regular básica para validar o formato do e-mail
      const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
      if (!emailRegex.test(email)) {
        emailError.textContent = 'Por favor, insira um e-mail válido.';
        return false;
      }
      return true;
    }